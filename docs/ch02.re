= Instagram APIから写真情報を取得しよう

== instagram gemをインストールする

Instagram API用に公式のGemが提供されているのでこちらを利用します。

@<href>{https://github.com/Instagram/instagram-ruby-gem}

Gemfileに下記を追加し、bundleコマンドでインストールします。

//source[/Gemfile]{

...
# instagram
gem 'instagram'

group :development, :test do
  gem 'dotenv-rails'
end
...

//}

//emlist{
$ bundle
//}

== InstagramクライアントIDを取得する

APIへアクセスするために、クライアントIDとクライアントシークレットが必要です。
Instagramのアプリケーション管理画面からCLIENT ID, CLIENT SECRETを取得しましょう。

@<href>{http://instagram.com/developer/clients/manage/}

//image[instagram][instagramアプリケーション管理画面]{
//}

Instagram APIへの接続確認をしてみましょう。
成功している場合は、images等を含んだハッシュが返ります。

//emlist{

$ bundle exec rails c
[1] pry(main)> Instagram.configure do |config|
[1] pry(main)*   config.client_id = 'f46bbe97d5d44c5e8d1432919f4b86e5'
[1] pry(main)*   config.client_secret = '23f75449716b45e6a5055b816ac37d42'
[1] pry(main)* end
[2] pry(main)> Instagram.media_popular
=> [{"attribution"=>nil,
  "videos"=>
  ...
  "images"=>
   {"low_resolution"=>
     {"url"=>
       "http://distilleryimage10.s3.amazonaws.com/ecee78bc6f1d11e3aa990e4f40f44b5e_6.jpg",
      "width"=>306,
      "height"=>306},
  ...
//}


== 接続設定をする

毎回client_id, client_secretを指定しなくて良いよう、設定ファイルに保存しておきましょう。

//source[/config/initializers/instagram.rb]{

require "instagram"
Instagram.configure do |config|
  config.client_id = ENV["INSTAGRAM_CLIENT_ID"]
  config.client_secret = ENV["INSTAGRAM_CLIENT_SECRET"]
end
//}

ここでIDをベタ書きしてしまうと、gitリポジトリにクライアントID, クライアントシークレットが保存されてしまってよろしくないので、環境変数から読み込むようにしています。

ここで、.bashや.zshに環境変数を設定すると、他の環境へ影響が出てしまうので、このプロジェクトでのみ適用されるよう、dotenvを利用します。

前章でdotenv-rails gemはインストール済みなので、プロジェクトルートに.envファイルを作成することでプロジェクトでのみ有効な環境変数を設定することが出来ます。
ここにクライアントID, クライアントシークレットを設定しましょう。
このファイルはリポジトリにプッシュしないよう、.ignoreに追記しておきます。

//source[/.env]{

INSTAGRAM_CLIENT_ID=[your client id]
INSTAGRAM_CLIENT_SECRET=[you client secret]

//}

dotenvについてより詳しくは、
@<href>{https://github.com/bkeepers/dotenv}
を御覧ください。


== キーワードで写真を取得しよう

tag_recent_media メソッドで、任意のタグがついた写真を取得することが出来ます。
日本語でタグを検索する場合はURIエンコードを忘れずにしましょう。

//list[list][ネコ写真の取得]{
$ bundle exec rails c
[1] pry(main)> medias = Instagram.tag_recent_media(URI.encode('猫'))
[2] pry(main)> medias.first.images.standard_resolution
=> {"url"=>
  "http://distilleryimage4.s3.amazonaws.com/dfeed81a6ef411e3b5bb12dcee79a560_8.jpg",
  "width"=>640,
  "height"=>640}
//}

instagram-ruby-gemについてより詳しくは、
@<href>{https://github.com/Instagram/instagram-ruby-gem}
を御覧ください。


最後に変更をgitリポジトリへコミットしておきましょう。

//emlist{
$ git add .
$ git commit -m 'Instagram APIから写真情報を取得できるようにした'
//}

== この章での変更点

ここまでの変更は下記コミットログで確認できます。

@<href>{https://github.com/mochiz/nyansta-demo/commit/391cfa38}
