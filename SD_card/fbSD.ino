void InitSD()
{
  if (!card.init(SPI_HALF_SPEED, chipSelect)) {
    //Nincs SD kártya
    Serial.println("No SD card");
    return;
  } else {
    //SD kártya rendben
    if (!volume.init(card)) {
      //rosz particio
      Serial.println("Wrong partition");
      return;
    };
  };

  if(SDFreeSize() > 25) {
    Serial.println("ok");
    SD.begin(chipSelect);
  };
  

};

uint32_t SDFreeSize()
{
  uint32_t volumesize;

  volumesize = volume.blocksPerCluster();    // clusters are collections of blocks
  volumesize *= volume.clusterCount();       // we'll have a lot of clusters
  volumesize *= 512;                         // SD card blocks are always 512 bytes - 512/
  volumesize /= 1024;
  volumesize /= 1024;
  return volumesize;
};

void SDCardWrite()
{
  int s = millis();
  File dataFile = SD.open("datalos.txt", FILE_WRITE);
  
  // if the file is available, write to it:
  if (dataFile) {
    dataFile.println(dataString);
    dataFile.close();
    // print to the serial port too:
    //Serial.println(dataString);
    Serial.println(millis()-s);
  }
  // if the file isn't open, pop up an error:
  else {
    Serial.println("error opening datalog.txt");
  }
}

