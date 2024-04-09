# Minitalk Projesi Nedir?

Minitalk projesi, UNIX sinyallerini kullanarak küçük bir veri iletişim programı geliştirmeyi amaçlayan projedir.

Proje genellikle bir istemci-sunucu mimarisi üzerine kuruludur. İstemci ve sunucu arasındaki iletişim, UNIX sinyalleri (genellikle SIGUSR1 ve SIGUSR2) kullanılarak gerçekleştirilir. İstemci, sunucuya belirli bir mesaj veya veri gönderir ve sunucu bu veriyi alır ve işler. Sunucu sonrasında alınan veriyi bir şekilde işler veya başka bir işlem gerçekleştirir.

# Minitalk Projesi Çalışma Mantığı

Minitalk projesinin çalışma mantığı genel olarak şu adımları içerir:

1. **Sunucu Başlatma**: İletişimin başlatılması için sunucu öncelikle başlatılır. Sunucu, kendi PID'sini görüntüler ve işlem beklemeye başlar.

2. **İstemci Bağlantısı**: İstemci, sunucuya bağlanmak için sunucunun PID'sini ve gönderilecek veriyi belirtir.

3. **İstemci Veri Gönderme**: İstemci, sunucuya veriyi göndermek için sunucunun PID'sini kullanarak sinyal gönderir. Örneğin, SIGUSR1 veya SIGUSR2 sinyalleri kullanılabilir. Gönderilen veri bu sinyalın bir parçası olarak iletilir.

4. **Sunucu Veriyi Alma**: Sunucu, sinyal alarak gelen veriyi işlemek üzere işlemeye başlar. Bu, sunucunun sinyal işleyicisi tarafından gerçekleştirilir. Sunucu, sinyali aldığında, veriyi okur ve işlemek üzere kullanır.

5. **Sunucu İşlem Yapma**: Sunucu aldığı veriyi işler. Bu işlem, sunucunun amacına bağlı olabilir. Örneğin, sunucu aldığı veriyi bir dosyaya yazabilir veya bir ekrana görüntüleyebilir.

6. **İstemci ve Sunucu İşlemlerinin Yinelemesi**: İstemci ve sunucu arasındaki bu iletişim döngüsü, belirli bir işlem tamamlanana kadar veya bir hata oluşana kadar devam eder. İstemci birden fazla veri gönderebilir ve sunucu bu verileri sırayla işleyebilir.

Bu şekilde, UNIX sinyalleri kullanılarak istemci ve sunucu arasında veri iletişimi sağlanır. İstemci ve sunucu arasındaki bu basit iletişim protokolü, işbirliği içinde çalışan farklı programlar arasında veri alışverişi için temel bir mekanizma sağlar.
