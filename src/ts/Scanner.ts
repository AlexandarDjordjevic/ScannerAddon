const NativeScanner = require('bindings')('addon').Scanner;

export interface Scanner {
    getName(): string;
}
