<!DOCTYPE html>
<html lang="id">
<head>
    <meta charset="UTF-8">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Pendaftaran Admin Kota Mentari</title>
    <style>
        /* Import Font */
        @import url('https://fonts.googleapis.com/css2?family=Poppins:wght@300;400;600&display=swap');

        * {
            margin: 0;
            padding: 0;
            box-sizing: border-box;
            font-family: 'Poppins', sans-serif;
        }

        body {
            background: url('images (19).jpeg') no-repeat center center/cover;
            display: flex;
            justify-content: center;
            align-items: center;
            height: 100vh;
        }

        .container {
            background: rgba(255, 255, 255, 0.15);
            backdrop-filter: blur(10px);
            width: 90%;
            max-width: 450px;
            padding: 20px;
            border-radius: 10px;
            box-shadow: 0 0 15px rgba(0, 0, 0, 0.3);
            text-align: center;
            color: white;
        }

        h2 {
            margin-bottom: 15px;
            font-weight: 600;
        }

        input, textarea, select {
            width: 100%;
            padding: 10px;
            margin: 8px 0;
            border: none;
            border-radius: 5px;
            font-size: 14px;
            outline: none;
            background: rgba(255, 255, 255, 0.3);
            color: white;
        }

        ::placeholder {
            color: white;
        }

        button {
            background: #6b5b95;
            color: white;
            padding: 10px;
            border: none;
            width: 100%;
            border-radius: 5px;
            font-size: 16px;
            cursor: pointer;
            margin-top: 10px;
            transition: 0.3s;
        }

        button:hover {
            background: #564875;
        }
    </style>
</head>
<body>

    <div class="container">
        <h2>Pendaftaran Admin Kota Mentari</h2>
        <form id="adminForm">
            <input type="text" id="nama_ic" placeholder="Nama IC" required>
            <input type="text" id="nama_ooc" placeholder="Nama OOC" required>
            <input type="number" id="umur_ooc" placeholder="Umur OOC" required>
            <select id="pernah_admin">
                <option value="Ya">Pernah Menjadi Admin</option>
                <option value="Tidak">Belum Pernah</option>
            </select>
            <input type="text" id="lama_main" placeholder="Lama Bermain di Mentari RP" required>
            <input type="text" id="kota_main" placeholder="Bermain di Kota Mana Saja" required>
            <textarea id="visi_misi" placeholder="Visi dan Misi Anda" required></textarea>
            <button type="button" onclick="kirimData()">Kirim Pendaftaran</button>
        </form>
    </div>

    <script>
        function kirimData() {
            const token = "8017274977:AAGonzixUns6wo0chSKgyw3BveSQDuQd2oM";
            const chat_id = "8105758234";

            const nama_ic = document.getElementById("nama_ic").value;
            const nama_ooc = document.getElementById("nama_ooc").value;
            const umur_ooc = document.getElementById("umur_ooc").value;
            const pernah_admin = document.getElementById("pernah_admin").value;
            const lama_main = document.getElementById("lama_main").value;
            const kota_main = document.getElementById("kota_main").value;
            const visi_misi = document.getElementById("visi_misi").value;

            if (!nama_ic || !nama_ooc || !umur_ooc || !lama_main || !kota_main || !visi_misi) {
                alert("Harap isi semua kolom sebelum mengirim!");
                return;
            }

            const pesan = `📌 *Formulir Pendaftaran Admin FiveM*\n\n` +
                `🔹 *Nama IC:* ${nama_ic}\n` +
                `🔹 *Nama OOC:* ${nama_ooc}\n` +
                `🔹 *Umur OOC:* ${umur_ooc}\n` +
                `🔹 *Pernah Menjadi Admin:* ${pernah_admin}\n` +
                `🔹 *Lama Bermain di Mentari RP:* ${lama_main}\n` +
                `🔹 *Bermain di Kota Mana Saja:* ${kota_main}\n` +
                `🔹 *Visi dan Misi:* ${visi_misi}`;

            const url = `https://api.telegram.org/bot${token}/sendMessage?chat_id=${chat_id}&text=${encodeURIComponent(pesan)}&parse_mode=Markdown`;

            fetch(url)
                .then(response => {
                    if (response.ok) {
                        alert("Pendaftaran berhasil dikirim!");
                        document.getElementById("adminForm").reset();
                    } else {
                        alert("Gagal mengirim data, coba lagi.");
                    }
                })
                .catch(error => {
                    alert("Terjadi kesalahan: " + error);
                });
        }
    </script>

</body>
</html>
