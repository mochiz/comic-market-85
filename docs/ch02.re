= Instagram APIから写真情報を取得しよう

== instagram gem をインストール

Instagram API用の公式Gemが提供されているのでこちらを利用します。

@<href>{https://github.com/Instagram/instagram-ruby-gem}

Gemfileに下記を追加して、bundleコマンドを実行しましょう。

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
//}


== 接続設定をする

client_id, client_secretを設定ファイルに保存しておきます。

//source[/config/initializers/instagram.rb]{

require "instagram"
Instagram.configure do |config|
  config.client_id = ENV["INSTAGRAM_CLIENT_ID"]
  config.client_secret = ENV["INSTAGRAM_CLIENT_SECRET"]
end
//}

gitリポジトリにクライアントID, クライアントシークレットが保存されないよう、環境変数として設定するようにします。

bashrc, zshrcに環境変数を設定すると複数のプロジェクトで衝突してしまうので、nyanstaアプリでのみ適用される環境変数を用意します。

dotenv-rails gem をインストール済みなので、プロジェクトルートに.envファイルを作成することでプロジェクトでのみ有効な環境変数を設定することが出来ます。
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
