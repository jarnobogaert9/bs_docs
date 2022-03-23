// Fork maakt een kopie van heel het ouderproces
// Voor een fork een heap doen, doen we niet graag
// Heap wordt ook gekopiëerd, dus moet je in al uw kind processen ook 'free' doen

// 1.
// fork()
// 2.
// fork()
// 3.
// fork()

// P

// 1.
//   P
//  /
// K


// 2.
//   P
//  / \
// K   K
// |
// K


// 3.
//   P ----
//  / \    |
// K   K   K
// |\   \
// K k   K
// |
// K

// 2^i -1 kind processen

// 3 forks
// 2^3 -1 = 2*2*2 -1 = 8-1 = 7 kind processen