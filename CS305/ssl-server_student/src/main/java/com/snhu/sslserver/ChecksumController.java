package com.snhu.sslserver;

import org.springframework.web.bind.annotation.GetMapping;
import org.springframework.web.bind.annotation.RestController;
import java.security.MessageDigest;
import java.security.NoSuchAlgorithmException;
import java.io.UnsupportedEncodingException;

@RestController
public class ChecksumController {

    private static final String DATA = "Hello World Check Sum!";  // Static data from FIXME

    @GetMapping("/checksum")
    public String getChecksum() {
        try {
            MessageDigest digest = MessageDigest.getInstance("SHA-256");  // Whitelisted algo 
            byte[] hashBytes = digest.digest(DATA.getBytes("UTF-8"));  // UTF-8 cons 
		// java 8? 
            StringBuilder sb = new StringBuilder();
            for (byte b : hashBytes) {
                sb.append(String.format("%02x", b & 0xff));
            }
            String hash = sb.toString();  // Expected: ab2aca08da294c82c67ae581bb5d309004220bece2ee07a84e13902029daa2cb
            return "Data: " + DATA + "\nSHA-256 Checksum: " + hash;
        } catch (NoSuchAlgorithmException | UnsupportedEncodingException e) {
            return "Error computing hash: " + e.getMessage();
        }
    }
}
