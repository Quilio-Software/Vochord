How it works:

// setting the algorithm sequence
avail_1 = [3, 5, 4, 6, 2, 7]
avail_2 = [3, 5, 6, 2, 4, 7]
avail_3 = [3, 5, 2, 4, 6, 7]
avail_4 = [3, 5, 2, 6, 7, 4]

// user input - chooses scale to create chords within
scale[] = [0, 2, 4, 5, 7, 10, 12]
mode1[] = scale[]
mode2[] = rotate (mode1[], -1)
. . .
mode7[] = rotate (mode6[], -1)

//user input - chord starting note
rootnote = 60
chordStartScaleIndex = getScaleIndex (chordStartMIDINote) //0, 1, 2, 3, 4, 5, 6


sendNote (activeMode[], chordStartScaleIndex)
activeMode = mode (chordStartScaleIndex)

// assign notes to nearby pads based on avail sequence
mapSequence (activeMode[], avail_1[])

// user input - adds second pad to create dyad
activeIndex = getIndex (userInputMidiNo, scale[])
sendNote (activeMode[], chordStartScaleIndex)

// avail_2 has activeIndex removed from it
removeNote (avail_2, chordStartScaleIndex)

// assign notes to nearby pads based on avail sequence
mapSequence (activeMode[], avail_2[])
