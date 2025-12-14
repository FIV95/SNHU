### Reflection on CS 305 Project Two

**Client summary:** Artemis Financial is this fictional finance company with an investigation tool for fraud stuff. They needed a secure server to handle data without leaks. The big issue was the app was super basic—HTTP only, no hashing, and deps full of old CVEs—so data could get sniffed or messed with.

**What I did well and why secure coding matters:** I think I nailed the step-by-step fixes, like adding the hash endpoint and TLS without breaking anything, using the Flow Diagram to spot issues early. Secure coding is huge because one slip can tank a company—lost data means fines or lawsuits, especially in finance. It keeps things running smooth and builds trust, so the business doesn't lose customers or get hacked.

**Challenging/helpful part:** The dep-check scan was tough—running it on the old Spring Boot 2.2.4 code spat out 147 CVEs, even after fixes, because we couldn't upgrade without messing the rubric. It was helpful for learning mitigations, but frustrating how the class used outdated stuff that made "complete" fixes impossible.

**Layers of security and future assessment:** I layered it with hash for integrity, TLS for encryption, and the scan for deps. In the future, I'd use SonarQube for auto-reviews and OWASP ZAP for dynamic tests to pick fixes—score by CVSS and business risk, like prioritizing RCE over DoS.

**Ensuring functional/secure:** Tested with mvn run and curl to check no errors, re-ran dep-check to see no new vulns (old ones stayed but mitigations covered them). Manual Flow review double-checked logic.

**Resources/tools/practices:** Iron-Clad Java for patterns, keytool for certs, Maven dep-check for scans. Practices like whitelisting algos and try-catch everywhere—super useful for next classes.
