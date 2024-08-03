# Installs mdbook
mkdir mdbook
# Consider using a service like renovatebot if you want to automatically update the version here.
curl -Lf https://github.com/rust-lang/mdBook/releases/download/v0.4.37/mdbook-v0.4.37-x86_64-unknown-linux-gnu.tar.gz | tar -xz --directory=./mdbook
echo `pwd`/mdbook >> $GITHUB_PATH

# Build the book
mdbook build

# If the gh-pages branch already exists, this will overwrite it
# so that the history is not kept, which can be very expensive.
git worktree add --orphan -B gh-pages gh-pages
cp -r book/ gh-pages
git config user.name "Deploy from CI"
git config user.email ""
cd gh-pages
git add -A
git commit -m 'deploy new book'
git push origin +gh-pages
cd ..