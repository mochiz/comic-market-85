= Railsアプリをセットアップしよう

//lead{
書き方のサンプルです。上書きするなりして消して下さい。
//}

== 必要なもの

 * Ruby 2.1
 * Bundler
 * Instagram アカウント


====[column] コラムについて

見出しの先頭に「[column]」と書くと、そこはコラムになります。
//image[imgcolumn][画像サンプル]{
//}

===[/column]

== ソースコードなどのリスト

リストには「//list」ブロックや「//emlist」ブロックを使います。

//list[list][リストのサンプル]{
int main(int argc, char **argv) {
  puts("OK");
  return 0;
}
//}

文中にリストを書くには「//emlist」になります。

//emlist{
def main
  puts "ok"
end
//}

== 画像

画像は「//image」ブロックを使います。

//image[imgsample][画像サンプル]{
//}


より詳しくは、
@<href>{https://github.com/kmuto/review/blob/master/doc/format.rdoc}
を御覧ください。
