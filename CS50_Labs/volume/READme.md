# Plan:
  Write a Program that takes in the input file of wav structure.
  Increase the volume of its data
  Write the modified data some output file of the wav structure.

# Wav file Structure as per the CS50 Rules:
  The first 44 bytes of the file is the header of the wav file that contains the meta data about the file for the computer to interpret that file.
  After the 44 bytes of the file, it has a periofic sequence of 2 bytes that contains the value of the audio signal at any instance of time.
  
# TODO
  1. Read the file from the input.wav and read the first 44 bytes and store it in some pointer variable(memory reference uses uint8_t)
  2. Read each consecutive audio signal and to increase the volume * it by the factor or to decrease the volume / it by the factor
  3. While modifying each of those consecutive signals of the program, store it in some pointer varaiable(memory reference uses int16_t)
  4. Takes the modified data of the header and the audio signals and write them to the new output.wav file.


# WARNING:
  The Program contains potential errors that may cause it to run properly
