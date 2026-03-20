See [doc/build-\*.md](/doc)
sudo apt-get update
sudo apt install build-essential rustc libssl-dev libyaml-dev zlib1g-dev libgmp-dev
curl https://mise.run | sh
echo 'eval "$(~/.local/bin/mise activate)"' >> ~/.bashrc
source ~/.bashrc
mise use --global ruby@3ruby --version
#=> 3.4.7gem update --systemmise use --global node@24.11.0

node -v
#=> 24.11.0git config --global color.ui true
git config --global user.name "Jonathan Tyler Combs"
git config --global user.email "jt_combs95@icloud.com"
ssh-keygen -t ed25519 -C "jt_combs95@icloud.com"