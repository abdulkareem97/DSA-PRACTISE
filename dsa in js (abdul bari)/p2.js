
function bulbsFlippedOddTimes(totalBulbs) {
    // Array to represent the bulbs (initially all off)
    let bulbs = Array(totalBulbs).fill(false);

    // Simulate flipping the bulbs
    for (let step = 2; step <= totalBulbs; step++) {
        for (let i = step - 1; i < totalBulbs; i += step) {
            bulbs[i] = !bulbs[i]; // Flip the bulb
        }
    }

    // Collect bulbs that remain on (flipped an odd number of times)
    const bulbsOn = [];
    for (let i = 0; i < totalBulbs; i++) {
        if (!bulbs[i]) {
            bulbsOn.push(i + 1); // Add bulb number (1-indexed)
        }
    }

    return bulbsOn;
}

// Example usage
const totalBulbs = 10; // Total number of bulbs
const result = bulbsFlippedOddTimes(totalBulbs);
console.log(`Bulbs that remain on: ${result}`);




