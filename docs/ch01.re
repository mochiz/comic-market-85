= Railsアプリをセットアップしよう

== 必要なもの

 * Ruby 2.1
 * PostgreSQL 9.3
 * Bundler 1.5
 * Git 1.8
 * Instagram アカウント

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

作成したファイルを保存しておきましょう。

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
Gemfileを以下のように変更します。

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

スーパーユーザーでnyansta-demo用のユーザーを作っておきましょう。

//emlist{
$ createuser nyansta-demo -s
//}

//emlist{
$ bundle exec rake db:create
$ bundle exec rake db:migrate
//}


//emlist{
$ bundle exec rails s
$ bundle exec rake db:migrate
//}

Railsアプリを起動してみましょう

//emlist{
$ bundle exec rails s
//}

http://localhost:3000 にアクセスしてみましょう。アプリが起動していることが確認できると思います。

//image[initialhome][初期状態のホームページ]{
//}


====[column] 不要なファイルをジェネレートしないようにする

初期設定のままだと、利用しないassetsやhelperが作成されてちょっと面倒なので、ジェネレートしないよう設定しています。
config/application.rbで様々な設定を変更できます。


//source[/config/application.rb]{

...
module NyanstaDemo
  class Application < Rails::Application
    config.generators do |g|
      # アセットをジェネレートしない
      g.assets false
      # ヘルパーをジェネレートしない
      g.helper false
      # ビュースペックをジェネレートしない
      g.view_specs false
    end

    # タイムゾーンをTokyoに変更
    config.time_zone = 'Tokyo'
    # 言語を日本語に変更
    config.i18n.default_locale = :ja
  end
end
...
//}

設定についてより詳しくは、
@<href>{http://guides.rubyonrails.org/configuring.html}
を御覧ください。

===[/column]
