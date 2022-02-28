function vowelsAndConsonants(s) {
    s = s.toLowerCase();
    const vowels = 'aeiou';
    for (const vowel of s) {
        if (vowels.includes(vowel)) {
            console.log(vowel);
        }
    }
    
    for (const cons of s) {
        if (!vowels.includes(cons)) {
            console.log(cons);
        }
    }
}

vowelsAndConsonants(process.argv[2]);
console.log('\n');
