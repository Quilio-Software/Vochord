//Algorithm

// user input (UI) - chooses C major scale
scale[] = [C, D, E, F, G, A, B]

// generating the modes based on scale
mode_1[] = scale[]                // [C, D, E, F, G, A, B]
mode_2[] = rotate (mode_1[], -1)  // [D, E, F, G, A, B, C]
. . .
mode_7[] = rotate (mode_6[], -1)  // [B, C, D, E, F, G, A]

// user input (keyboard) - sets root note
rootNote = A
activeMode = setMode (scale.getIndex (A)) // [A, B, C, D, E, F, G]

// user input (launchpad) - first pad pressed
sendNote (activeMode[], chordStartScaleIndex) // 'A' sent to virtual instrument

// serially assign notes to concentric pads based on sequence,
// which traverses the activeMode to choose which notes to map serially outwards from the most recently pressed pad
seq_1 = [3, 5, 4, 6, 2, 7]
seq_2 = [3, 5, 6, 2, 4, 7]
seq_3 = [3, 5, 2, 4, 6, 7]
seq_4 = [3, 5, 2, 6, 7, 4]

mapSequence (activeMode[], seq[])
// [A, B, C, D, E, F, G] <- [3, 5, 4, 6, 2, 7]
// map => C, E, D, F, B, G

// user input (launchpad) - additional pads pressed to add more notes to chord

// user saves chord in piano roll (or memorizes it if they're brave enough)
