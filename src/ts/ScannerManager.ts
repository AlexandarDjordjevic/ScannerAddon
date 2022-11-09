import { Scanner } from "./Scanner";
const NativeScannerManager = require('bindings')('addon').ScannerManager;


export class ScannerManager extends NativeScannerManager {
    get scanners(): Scanner[] {
        return super.getScanners();
    }
}
