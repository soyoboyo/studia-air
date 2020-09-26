package com.jza.trains.services;

import org.springframework.stereotype.Service;

@Service
public class CmdService {

	public void exportData() {
		try {
			String db = "trains";
			String collection = "trains";
			String file = "A:\\trains.json";
			Process process = Runtime.getRuntime().exec(new String[]{"cmd.exe", "/c", "mongoexport " + " --db " + db + " -c " + collection + " --out " + file});
		} catch (Exception e) {
			e.getStackTrace();
		}

	}

	public void importData() {
		try {
			String db = "trains";
			String collection = "trains";
			String file = "A:\\trains.json";
			Process process = Runtime.getRuntime().exec(new String[]{"cmd.exe", "/c", "mongoimport " + " --db " + db + " -c " + collection + " --file " + file + " --upsert"});
		} catch (Exception e) {
			e.getStackTrace();
		}
	}

}
