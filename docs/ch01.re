= Railsアプリをセットアップしよう

== Railsアプリを新規作成する

Railsアプリを新規作成します。Gemのインストールは別途行うので、--skip-bundleオプションをつけましょう。

//emlist{
$ rails new nyansta-demo --skip-bundle
      create
      create  README.rdoc
      create  Rakefile
      create  config.ru
      create  .gitignore
      create  Gemfile
      create  app
      create  app/assets/javascripts/application.js
      create  app/assets/stylesheets/application.css
      create  app/controllers/application_controller.rb
      create  app/helpers/application_helper.rb
//}

都度gitリポジトリへ保存しておきましょう。

//emlist{
$ git init
Initialized empty Git repository in /Users/asakura/Sites/github/mochiz/nyansta-demo/.git/
$ git add .
$ git commit -m 'initial commit'
[master (root-commit) 74a30c8] initial commit
 52 files changed, 702 insertions(+)
 create mode 100644 .gitignore
 create mode 100644 Gemfile
 create mode 100644 README.rdoc
 create mode 100644 Rakefile
 ...
//}


== 必要なGemをインストールする

bundleコマンドでGemをインストールしましょう。
内容は以下のとおりです。

//source[/Gemfile]{

source 'https://rubygems.org'
ruby '2.1.0'

gem 'rails', '4.0.2'
gem 'pg'

# assets
gem 'sass-rails', '~> 4.0.0'
gem 'uglifier', '>= 1.3.0'

# javascript
gem 'coffee-rails', '~> 4.0.0'
gem 'jquery-rails'
gem 'turbolinks'
gem 'jbuilder', '~> 1.2'

group :development, :test do
  gem 'rspec-rails'
end

group :development do
  gem 'better_errors'
  gem 'binding_of_caller'
  gem 'bullet'
  gem 'byebug'
  gem 'pry-rails'
  gem 'rails_best_practices'
  gem 'rubocop'
end

group :test do
  gem 'capybara'
  gem 'factory_girl_rails'
  gem 'poltergeist'
  gem 'shoulda'
  gem 'vcr'
  gem 'webmock'
end
//}

bundle installコマンドを実行します。システムのGemと切り離すため、--pathオプションを追加しています。

//emlist{
$ bundle install --path vendor/bundle
Fetching gem metadata from https://rubygems.org/.........
Fetching additional metadata from https://rubygems.org/..
Resolving dependencies...
Using rake (10.1.1)
...
Your bundle is complete!
It was installed into ./vendor/bundle
//}


== データベースをセットアップする

今回のアプリではデータベースは必要ないのですが、herokuへデプロイするためPostgreSQL用の設定に変更します。

//source[/config/database.yml]{

development:
  adapter: postgresql
  encoding: unicode
  database: nyansta-demo_development
  pool: 5
  username: nyansta-demo
  password:

test:
  adapter: postgresql
  encoding: unicode
  database: nyansta-demo_test
  pool: 5
  username: nyansta-demo
  password:

production:
  adapter: postgresql
  encoding: unicode
  database: nyansta-demo_production
  pool: 5
  username: nyansta-demo
  password:
//}

usernameに既存のユーザー名を使用するか、createuserコマンドでユーザーを作成してください。

//emlist{
$ createuser nyansta-demo -s
//}

DBのマイグレーションを行います。

//emlist{
$ bundle exec rake db:create
$ bundle exec rake db:migrate
//}

== Railsアプリを起動する

rails serverコマンドを実行して、http://localhost:3000 にアクセスしてみましょう。次のような画面が表示され、アプリの起動を確認できます。

//emlist{
$ bundle exec rails s
//}


//image[initialhome][初期状態のホームページ]{
//}


最後に変更をgitリポジトリへコミットしておきましょう。

//emlist{
$ git add .
$ git commit -m 'Instagram APIから写真情報を取得できるようにした'
//}

== この章での変更点

ここまでの変更は下記コミットログで確認できます。

@<href>{https://github.com/mochiz/nyansta-demo/commit/6a8b519}



====[column] 不要なファイルをジェネレートしないようにする

初期設定のままだと、コントローラー作成時に、不要なassetsやhelperが作成されて鬱陶しいので、不要なファイルはジェネレートしないよう以下のように設定しています。

//source[/config/application.rb]{

...
module NyanstaDemo
  class Application < Rails::Application
    config.generators do |g|
      g.assets false     # アセットをジェネレートしない
      g.helper false     # ヘルパーをジェネレートしない
      g.view_specs false # ビュースペックをジェネレートしない
    end

    config.time_zone = 'Tokyo'       # タイムゾーンをTokyoに変更
    config.i18n.default_locale = :ja # 言語を日本語に変更
  end
end
...
//}

設定についてより詳しくは、公式のガイド等をご確認ください。

@<href>{http://guides.rubyonrails.org/configuring.html}

===[/column]

