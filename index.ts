import { ScannerManager } from "./src/ts/ScannerManager";
import { Scanner } from './src/ts/Scanner';

const scm = new ScannerManager();
scm.scanners.forEach((scanner: Scanner) => console.log(scanner.getName()));
