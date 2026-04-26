import time
import requests
import os

# --- CONFIGURATION ---
# Replace this with YOUR computer's IP address
AI_SERVICE_IP = "10.226.98.157" 
AI_SERVICE_URL = f"http://{AI_SERVICE_IP}:5000/triage"

# The path to where Snort is writing its alerts
SNORT_LOG_PATH = "C:/Snort/log/alert.ids" # Change this to the actual path

def watch_and_push():
    print(f"Watching Snort logs and sending to {AI_SERVICE_URL}...")
    
    # Open the file and jump to the end so we only send NEW logs
    with open(SNORT_LOG_PATH, "r") as f:
        f.seek(0, 2)
        
        while True:
            line = f.readline()
            if not line:
                time.sleep(0.5)
                continue
            
            # Create the payload for your main.py
            # Snort logs are usually raw text, so we wrap them in a dict
            payload = {
    		"alert": line.strip(),
    		"sensor_id": "remote_snort_node",
    		"known_macs": []
		}

            try:
                response = requests.post(AI_SERVICE_URL, json=payload, timeout=5)
                if response.status_code == 200:
                    print("Successfully pushed to AI Brain.")
                else:
                    print(f"Brain rejected log: {response.status_code}")
            except Exception as e:
                print(f"Error reaching AI Brain: {e}")

if __name__ == "__main__":
    watch_and_push()