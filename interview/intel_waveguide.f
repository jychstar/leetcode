

         Program main
         implicit none
         integer i,j,k,l,mode,n, niter
         logical solve,plot
         double precision nf,ns,nc,ko,h,lam,gs,gc
         double precision kmin,kmax, kmode
         double precision beta,gams,gamc
         double precision ktemp(500),delk,guess
         double precision cotpl(500),fpl(500),num,den
         double precision cot,zro,fix,kf,thr,kfsol(20)

         print*, "hello, my name is _Slab Guide_"

c -- to plot or to solve? pick ONE!!
c --         solve=.true.
         plot=.false.

c -- set up the constants
         nc=1.4d0
         nf=1.5d0
         ns=1.45d0
         h=5.0d0
         lam=1d0
         ko=2*3.14159/lam
         gs=(nf*nf-ns*ns)*ko*ko
         gc=(nf*nf-nc*nc)*ko*ko

         print*, "----------------------"
         print*, "nc:",nc
         print*, "----------------------"
         print*, "nf:",nf, "}-h"
         print*, "----------------------"
         print*, "ns:",ns
         print*, "----------------------"
         print*, "h:",h
         print*, "ko:",ko
         print*, "constant part of gamma_c:",gc
         print*, "constant part of gamma_s:",gs
         print*, "---------------------"

c -- set up the grid
         kmin=0d0
         kmax=(gs)**(0.5)  ! change
         kmode = 3.1415926d0 / h   ! add  mode range for  a single mode
         if (plot) then
             n=500  ! grid size for plotting
         else
             n=10  ! grid for solve
         endif
         delk=(kmax-kmin)/n

         ktemp(1)=kmin
         do i=2,n
         ktemp(i)=ktemp(i-1)+delk
         end do

c -- generate pretty picture
        if (plot) then
         do i=2,n
         cotpl(i)=cos(ktemp(i)*h)/sin(ktemp(i)*h)
         gamc=(gc-ktemp(i)*ktemp(i))**(0.5)
         gams=(gs-ktemp(i)*ktemp(i))**(0.5)
         den=ktemp(i)*(gams+gamc)
         num=ktemp(i)*ktemp(i)-gamc*gams
         fpl(i)=num/den
         print*, i, ktemp(i)*h,cotpl(i),fpl(i)
         end do

        else if (solve) then

c -- simple shift solver
400     do j=2,n
         print*, "Solution:",j
         gamc=0d0
         gams=0d0
         cot=0d0
         zro=0d0
         guess=0d0
         fix=0d0
         thr=1d-7
         niter=100      ! increase from 20 to 100
         kf=ktemp(j)
         i=0

200      i=i+1
        mode = int (kf / kmode)  ! add to indicate mode order
         kf=kf+fix
         if (int (kf/kmode) /= mode) then
            kf= mode*kmode + mod(kf, kmode)   ! pull kf back to its mode range
        end if
         guess=kf*h
         cot=cos(guess)/sin(guess)
         gamc=(gc-kf*kf)**(0.5)
         gams=(gs-kf*kf)**(0.5)
         den=kf*(gams+gamc)
         num=kf*kf-gamc*gams
         zro=cot-num/den
         if(abs(zro).lt.thr) then
         print*, i,"am i zero?",zro
         print*, "math gods have smiled upon us!"
          kfsol(j)=kf
          go to 300
         end if
         fix=0.03*zro    ! decrease from 0.1 to 0.03
         if(i.lt.niter) then
          go to 200
         else
         print*, "--math gods hate you--"
         print*, "-better luck next root-"
c          go to 400
         end if

300      print*, "Kf*h:",kf*h
         print*, "Kf:",kf
         end do

c -- all done make a nice table
         print*, "Solution Summary"
         print*, "-----------------------------------------------------"
         print*, "            Kf            |         Kf*h             "
         print*, "====================================================="
         do j=1,n
         print*, kfsol(j),"|",kfsol(j)*h
         print*, "-----------------------------------------------------"
         end do
        end if
        end
