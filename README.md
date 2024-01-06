* How it works:

avail_1 = [3,5,4,6,2,7]
avail_2 = [3,5,6,2,4,7]
avail_3 = [3,5,2,4,6,7]
avail_4 = [3,5,2,6,7,4]

//user input - chooses scale

//setScale
scale[] = [0,2,4,5,7,10,12]
mode1[] = rotate(scale[],-1)
mode2[] = rotate(mode1[],-1)l
. . .
mode7[] = rotate(mode6[],-1)

//user input - hits first pad
rootIndex = getIndex(userInputMidiNo,scale[])

//send note
sendNote(activeMode[],rootIndex)
activeIndex = rootIndex
activeMode = mode(activeIndex)

//assign notes to nearby pads based on avail sequence
mapSequence(activeMode[],avail_1[])

