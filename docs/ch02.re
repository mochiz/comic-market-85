= InstagramAPI から写真情報を取得しよう

== instagram gem をインストール

Instagram API用の公式Gemが提供されているのでこちらを利用します。


//list[list][Instagramの設定]{
Instagram.configure do |config|
  config.client_id = "YOUR_CLIENT_ID"
  config.client_secret = "YOUR_CLIENT_SECRET"
end
//}

//list[list][ネコ写真の取得]{
$ medias = Instagram.tag_recent_media(URI.encode('猫'))
$ medias.first.images.standard_resolution
=> {"url"=>
 "http://distilleryimage7.s3.amazonaws.com/df94ba126d9411e3948212ff5e681f83_8.jpg",
 "width"=>640,
 "height"=>640}
//}

== 接続設定をする

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

== キーワードで写真を取得

tag_recent_media メソッドで写真を取得することが出来ます。

@medias で画像URLやキャプションが取得できたので、Viewで表示してみましょう

//source[/app/controllers/home_controller.rb]{

class HomeController < ApplicationController
  def index
    @medias = Instagram.tag_recent_media(URI.encode('猫'))
  end
end

//}
