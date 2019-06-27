#!/usr/local/bin/perl
use strict;
use Time::Local;
my @list;
my $id;
my $i;
my %obs_p;

open (IN,"amedaslist.csv") or die $!;
while (my$amedas = <IN>){
 chomp ($amedas);
 	my ($id,$a,$i,$s,$lat,$lon,$x) = split(/,/,$amedas);
 push (@list,$id);
 $i++;
}
open (INPUT,"obs/") or die $!;
while($line = <INPUT>){
 chomp ($line); 
 my @dat = split(/,/,$line);
 foreach $i(@dat){
  if($time eq "HEAD:DateTime" && $i eq "ObsPrec1h"){
  $obs_p{$dat[$time]} = $dat[$i]; 
 #my($time,$id,$lat,$lon,$otemp,$op,$ObsRH,$ObsDewTemp,$ObsWndSpd,$ObsWndDir,$ObsGustSpd,$ObsGustDir,$ObsSnowDpt,$ObsSnowDif,$ObsSnowFall,$ObsSilTemp,$ObsBrgTemp,$ObsV) = split(/,/,$line);
}
my $start_yyyy = 2019;
my $start_mm   = 06;
my $start_dd   = 24;
my $start_hh   = 00;
my $start_mn   = 00;
my $start_ss   = 00;

my $end_yyyy = 2019;
my $end_mm   = 06;
my $end_dd   = 26;
my $end_hh   = 23;
my $end_mn   = 00;
my $end_ss   = 00;


# timegm ... convert date to second ( from 1970/01/01 00:00- )
my $start_sec = timegm($start_ss,$start_mn,$start_hh,$start_dd,$start_mm - 1,$start_yyyy - 1900);
my $end_sec   = timegm($end_ss,$end_mn,$end_hh,$end_dd,$end_mm - 1,$end_yyyy - 1900);
foreach $id(@list){
for( my $sec = $start_sec; $sec <= $end_sec ; $sec = $sec + 3600 ){
  my ($ss,$mn,$hh,$dd,$mm,$yyyy) = gmtime($sec);
  $yyyy = $yyyy+1900;
  $mm = $mm+1;
#  print "$yyyy,$mm,$dd,$hh\n";

  $yyyy = sprintf("%04d",$yyyy);
  $mm   = sprintf("%02d",$mm);
  $dd   = sprintf("%02d",$dd);
  $hh   = sprintf("%02d",$hh);
#  print "obs/$yyyy/$mm/$dd/$hh/$id\n";

}
}


