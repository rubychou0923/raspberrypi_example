
filetype on
"let Tlist_Auto_Open = 1

"Remove the Windows ^M
map <Leader>m mz:%s/\r$//g<cr>`z

"Nerd Tree commands and options
map <Leader>, :NERDTreeToggle<cr>
map <F8> :TlistToggle<CR>


nmap <C-\>s :cs find s <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>g :cs find g <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>c :cs find c <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>t :cs find t <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>e :cs find e <C-R>=expand("<cword>")<CR><CR>	
nmap <C-\>f :cs find f <C-R>=expand("<cfile>")<CR><CR>	
nmap <C-\>i :cs find i ^<C-R>=expand("<cfile>")<CR>$<CR>
nmap <C-\>d :cs find d <C-R>=expand("<cword>")<CR><CR>	
map <F9> :%s/\r//g
map <F6> :%!xxd
map <F5> :%!xxd -r
let Tlist_WinWidth = 20

set number
set smartindent
set tabstop=4
set shiftwidth=4
set expandtab
syntax on
cs add cscope.out

