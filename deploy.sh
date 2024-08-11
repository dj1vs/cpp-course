# Consider using a service like renovatebot if you want to automatically update the version here.
echo `pwd`/mdbook >> $GITHUB_PATH

# Build the book
mdbook build

# If the gh-pages branch already exists, this will overwrite it
# so that the history is not kept, which can be very expensive.
git worktree add --orphan -B gh-pages gh-pages
cp -r book/ gh-pages
cd gh-pages
git add -A
git commit -m 'deploy new book'
git push origin +gh-pages
cd ..