<p style="margin-bottom: 12.0pt; line-height: normal; background: white;"><strong><span style="font-size: 12.0pt; font-family: 'Segoe UI',sans-serif; color: #24292e;">LABİRENT OYUNU</span></strong></p>
<p style="margin-bottom: 12.0pt; line-height: normal; background: white;"><strong><span style="font-size: 12.0pt; font-family: 'Segoe UI',sans-serif; color: #24292e;">&Ouml;zet:</span></strong></p>
<p style="margin-bottom: 10.0pt; line-height: 115%; text-autospace: none;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Bağlantılı liste (link list) ve yığın kullanılarak rastgele oluşturulan labirentler &uuml;zerinden &ccedil;ıkışa ulaşması istenen ve programlama dili olarak C dili kullanılarak ger&ccedil;ekleştirilen bir labirent oyunu geliştirilmiştir.</span></p>
<p style="margin-bottom: 12.0pt; line-height: normal; background: white;"><strong><span style="font-size: 12.0pt; font-family: 'Segoe UI',sans-serif; color: #24292e;">Giriş:</span></strong></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">İlk başta kullanıcıdan matris boyutu yani labirent boyutu istenilmektedir. Buna bağlı olarak matrisin maksimum boyutunun ekranda g&ouml;r&uuml;nmesi hedeflenmektedir. </span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Matris değerleri rastgele (1 ve 0) olarak &uuml;retilmiştir, 1 yol var, 0 ise yol yok şeklindedir.</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Ama&ccedil; 1&rsquo;leri takip ederek &ccedil;ıkışa ulaşmaktır. Bunun i&ccedil;in o an bulunan konumun 4 komşusunu (aşağı, yukarı, sağ, sol) kontrol ederek 1 olan elemanı yani&nbsp; gidilecek olan yol bulunuyor.</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Rastgele matrisi tanımladıktan sonra &ccedil;eşitli d&ouml;ng&uuml;ler ve karşılaştırma ifadeleri kullanarak &ccedil;ıkış yolu bulunuyor. Ayrıca komşu elemanları kontrol ederek gidiş y&ouml;n&uuml;n&uuml; belirleyen ve sonucu d&ouml;nd&uuml;ren bir algoritma tasarlanıyor.</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Sonu&ccedil; olarak kullanıcıdan alınan giriş ve &ccedil;ıkış konumlarına g&ouml;re yol var mı yok mu sorularına cevap bulunuyor. Eğer yol varsa sadece yol &uuml;zerinde olan 1&rsquo;ler g&ouml;steriliyor diğer labirent elemanları 0 yapılıyor ve bulunan yol yazdırılıyor. Eğer yol yok ise hata mesajı veriyor ve tekrar giriş yapması isteniyor.&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; </span></p>
<p style="margin-bottom: 12.0pt; line-height: normal; background: white;"><strong><span style="font-size: 12.0pt; font-family: 'Segoe UI',sans-serif; color: #24292e;">Genel Yapı:</span></strong></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Kullanıcıdan rastgele matris yani labirenti oluşturmak i&ccedil;in boyut bilgileri olan satir sayisi ve sutun sayisi bilgilerinin girilmesi isteniyor. Bu bilgilere bağlı olarak labirent oluşturuluyor. </span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Daha sonra labirentin giriş noktası ve &ccedil;ıkış noktası i&ccedil;in gereken satir ve s&uuml;tun numara bilgileri kullanıcıdan isteniyor.</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Kullanıcıdan alınan giriş ve &ccedil;ıkış numara bilgilerine g&ouml;re &ccedil;ıkış varsa eğer yol boyunca yol &uuml;zerinde olan 1&rsquo;ler g&ouml;steriliyor diğer labirent elemanları 0 yapılıyor.</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 35.4pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Daha sonra bulunan yol ekrana yazdırılıyor.</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">Eğer kullanıcının vermiş olduğu giriş ve &ccedil;ıkış numara bilgilerine g&ouml;re yol bulunamadıysa hata mesajı verilip yeniden giriş ve &ccedil;ıkış numara bilgisi isteniyor.</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">&nbsp;</span></p>
<p style="line-height: 115%; text-autospace: none; margin: 0cm 0cm 10.0pt 36.0pt;"><span style="font-size: 10.0pt; line-height: 115%; font-family: 'Times New Roman',serif;">&nbsp;</span></p>
<p>&nbsp;</p>
