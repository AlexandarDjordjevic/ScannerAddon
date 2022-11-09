const NativeScanner = require('bindings')('addon').Scanner;

export class Scanner extends NativeScanner {
    getName(): string {
        console.log("Scanner get name");
        return super.getName();
    }
}
