#include "stdafx.h"
#include "../std/Equip.h"
#include "../server/User.h"


// 书本 book
#include "../item/book/18muou.h"
#include "../item/book/18niou.h"
#include "../item/book/allow_letter.h"
#include "../item/book/bagua0.h"
#include "../item/book/bagua1.h"
#include "../item/book/blade_book.h"
#include "../item/book/bojuan.h"
#include "../item/book/book2.h"
#include "../item/book/book_iron.h"
#include "../item/book/book_paper.h"
#include "../item/book/book_silk.h"
#include "../item/book/book_stone.h"
#include "../item/book/bufa.h"
#include "../item/book/daodejing.h"
#include "../item/book/daodejing_i.h"
#include "../item/book/daodejing_ii.h"
#include "../item/book/dodgebook.h"
#include "../item/book/dujing_1.h"
#include "../item/book/dujing_2.h"
#include "../item/book/fojing10.h"
#include "../item/book/fojing100.h"
#include "../item/book/fojing101.h"
#include "../item/book/fojing11.h"
#include "../item/book/fojing20.h"
#include "../item/book/fojing200.h"
#include "../item/book/fojing201.h"
#include "../item/book/fojing21.h"
#include "../item/book/force_book.h"
#include "../item/book/hand_book.h"
#include "../item/book/jinshe1.h"
#include "../item/book/jinshe2.h"
#include "../item/book/jinshe3.h"
#include "../item/book/jinyantu.h"
#include "../item/book/jiuyang1.h"
#include "../item/book/jiuyang2.h"
#include "../item/book/jiuyang3.h"
#include "../item/book/jiuyang4.h"
#include "../item/book/jiuyin1.h"
#include "../item/book/jiuyin2.h"
#include "../item/book/laozi1.h"
#include "../item/book/laozi13.h"
#include "../item/book/laozi16.h"
#include "../item/book/laozi18.h"
#include "../item/book/laozi2.h"
#include "../item/book/laozi8.h"
#include "../item/book/lbook1.h"
#include "../item/book/lbook2.h"
#include "../item/book/lbook3.h"
#include "../item/book/literateb4.h"
#include "../item/book/liumai_sword.h"
#include "../item/book/liuyang_book1.h"
#include "../item/book/liuyang_book2.h"
#include "../item/book/ls_book.h"
#include "../item/book/mizong_book.h"
#include "../item/book/parry_book.h"
//#include "../item/book/pixie_sword_book.h"
#include "../item/book/qiankun_xinfa.h"
#include "../item/book/qijianpu.h"
#include "../item/book/qinpu.h"
#include "../item/book/quanpu.h"
#include "../item/book/qunxing_tu.h"
#include "../item/book/shoufa.h"
#include "../item/book/six_book.h"
#include "../item/book/skin.h"
#include "../item/book/skybook.h"
#include "../item/book/staff_book.h"
#include "../item/book/strike_book.h"
#include "../item/book/sun_book.h"
#include "../item/book/sword_book1.h"
#include "../item/book/sword_book2.h"
#include "../item/book/throw_book.h"
#include "../item/book/wuji1.h"
#include "../item/book/wuji2.h"
#include "../item/book/wuji3.h"
#include "../item/book/xisuijing.h"
#include "../item/book/xuanfeng_book.h"
#include "../item/book/yijing0.h"
#include "../item/book/yijing1.h"
#include "../item/book/yijing2.h"
#include "../item/book/yijing3.h"
#include "../item/book/yijinjing.h"
#include "../item/book/ylbian.h"
#include "../item/book/yljing.h"
#include "../item/book/yljian.h"
#include "../item/book/yljianpu.h"
#include "../item/book/yljing1.h"
#include "../item/book/yljing2.h"
#include "../item/book/yunv_swordb.h"
#include "../item/book/yunvjing1.h"
#include "../item/book/yunvjing2.h"
#include "../item/book/zhangfapu.h"
#include "../item/book/zhemei_book1.h"
#include "../item/book/zhemei_book2.h"
//#include "../item/book/zhengqi_book.h"
#include "../item/book/zhifapu.h"
#include "../item/book/zixia_book.h"
#include "../item/book/guide.h"
#include "../item/book/map.h"
#include "../item/book/kuihua.h"
#include "../item/book/paper.h"
#include "../item/book/book14_1.h"
#include "../item/book/book14_2.h"
#include "../item/book/book14_3.h"
#include "../item/book/book14_4.h"
#include "../item/book/book14_5.h"
#include "../item/book/book14_6.h"
#include "../item/book/book14_7.h"
#include "../item/book/book14_8.h"

#include "../item/book/miaoshou.h"
#include "../item/book/hanyuepai.h"
#include "../item/book/qiankun_fake.h"

#include "../item/book/musicbook1.h"
#include "../item/book/musicbook2.h"

//5MM
#include "../item/book/chanhe_book1.h"
#include "../item/book/chanhe_book2.h"
#include "../item/book/chanhe_book3.h"
#include "../item/book/chanhe_book4.h"
#include "../item/book/jixiao_book1.h"
#include "../item/book/jixiao_book2.h"
#include "../item/book/jixiao_book3.h"
#include "../item/book/jixiao_book4.h"
#include "../item/book/hejianjing.h"
#include "../item/book/tangshoumichuan.h"
#include "../item/book/club_book.h"
#include "../item/book/hammer_book.h"
#include "../item/book/wumu_book1.h"
#include "../item/book/kao_book.h"
#include "../item/book/kill_hammer_book.h"

//qinbo 2002、3、14
#include "../item/book/xiangsijianpu.h"

#include "../item/book/yicai_book1.h"
#include "../item/book/yicai_book2.h"
#include "../item/book/kuihua_pro.h"

//jj
#include "../item/book/jh_zhinan1.h"


CContainer * Load_Book(string item_name)
{
	CContainer * t = NULL;

	//  书本 book
	if(item_name == "18muou")
		t = new CI18muou();
	else if(item_name == "18niou")
		t = new CI18niou();
	else if(item_name == "allow_letter")
		t = new CIallow_letter();
	else if(item_name == "bagua0")
		t = new CIbagua0();
	else if(item_name == "bagua1")
		t = new CIbagua1();
	else if(item_name == "blade_book")
		t = new CIblade_book();
	else if(item_name == "bojuan")
		t = new CIbojuan();
	else if(item_name == "book2")
		t = new CIbook2();
	else if(item_name == "book_iron")
		t = new CIbook_iron();
	else if(item_name == "book_paper")
		t = new CIbook_paper();
	else if(item_name == "book_silk")
		t = new CIbook_silk();
	else if(item_name == "book_stone")
		t = new CIbook_stone();
	else if(item_name == "bufa")
		t = new CIbufa();
	else if(item_name == "daodejing")
		t = new CIdaodejing();
	else if(item_name == "daodejing_i")
		t = new CIdaodejing_i();
	else if(item_name == "daodejing_ii")
		t = new CIdaodejing_ii();
	else if(item_name == "dodgebook")
		t = new CIdodgebook();
	else if(item_name == "dujing_1")
		t = new CIdujing_1();
	else if(item_name == "dujing_2")
		t = new CIdujing_2();
	else if(item_name == "force_book")
		t = new CIforce_book();
	else if(item_name == "fojing10")
		t = new CIfojing10();
	else if(item_name == "fojing100")
		t = new CIfojing100();
	else if(item_name == "fojing101")
		t = new CIfojing101();
	else if(item_name == "fojing11")
		t = new CIfojing11();
	else if(item_name == "fojing20")
		t = new CIfojing20();
	else if(item_name == "fojing200")
		t = new CIfojing200();
	else if(item_name == "fojing201")
		t = new CIfojing201();
	else if(item_name == "fojing21")
		t = new CIfojing21();
	else if(item_name == "hand_book")
		t = new CIhand_book();
	else if(item_name == "jinshe1")
		t = new CIjinshe1();
	else if(item_name == "jinshe2")
		t = new CIjinshe2();
	else if(item_name == "jinshe3")
		t = new CIjinshe3();
	else if(item_name == "jinyantu")
		t = new CIjinyantu();
	else if(item_name == "jiuyang1")
		t = new CIjiuyang1();
	else if(item_name == "jiuyang2")
		t = new CIjiuyang2();
	else if(item_name == "jiuyang3")
		t = new CIjiuyang3();
	else if(item_name == "jiuyang4")
		t = new CIjiuyang4();
	else if(item_name == "jiuyin1")
		t = new CIjiuyin1();
	else if(item_name == "jiuyin2")
		t = new CIjiuyin2();
	else if(item_name == "laozi1")
		t = new CIlaozi1();
	else if(item_name == "laozi13")
		t = new CIlaozi13();
	else if(item_name == "laozi16")
		t = new CIlaozi16();
	else if(item_name == "laozi18")
		t = new CIlaozi18();
	else if(item_name == "laozi2")
		t = new CIlaozi2();
	else if(item_name == "laozi8")
		t = new CIlaozi8();
	else if(item_name == "lbook1")
		t = new CIlbook1();
	else if(item_name == "lbook2")
		t = new CIlbook2();
	else if(item_name == "lbook3")
		t = new CIlbook3();
	else if(item_name == "literateb4")
		t = new CIliterateb4();
	else if(item_name == "liumai_sword")
		t = new CIliumai_sword();
	else if(item_name == "liuyang_book1")
		t = new CIliuyang_book1();
	else if(item_name == "liuyang_book2")
		t = new CIliuyang_book2();
	else if(item_name == "ls_book")
		t = new CIls_book();
	else if(item_name == "mizong_book")
		t = new CImizong_book();
	else if(item_name == "parry_book")
		t = new CIparry_book();
//	else if(item_name == "pixie_sword_book")
//		t = new CIpixie_sword_book();
	else if(item_name == "qiankun_xinfa")
		t = new CIqiankun_xinfa();
	else if(item_name == "qijianpu")
		t = new CIqijianpu();
	else if(item_name == "qinpu")
		t = new CIqinpu();
	else if(item_name == "quanpu")
		t = new CIquanpu();
	else if(item_name == "qunxing_tu")
		t = new CIqunxing_tu();
	else if(item_name == "shoufa")
		t = new CIshoufa();
	else if(item_name == "six_book")
		t = new CIsix_book();
	else if(item_name == "skin")
		t = new CIskin();
	else if(item_name == "skybook")
		t = new CIskybook();
	else if(item_name == "staff_book")
		t = new CIstaff_book();
	else if(item_name == "strike_book")
		t = new CIstrike_book();
	else if(item_name == "sun_book")
		t = new CIsun_book();
	else if(item_name == "sword_book1")
		t = new CIsword_book1();
	else if(item_name == "sword_book2")
		t = new CIsword_book2();
	else if(item_name == "throw_book")
		t = new CIthrow_book();
	else if(item_name == "wuji1")
		t = new CIwuji1();
	else if(item_name == "wuji2")
		t = new CIwuji2();
	else if(item_name == "wuji3")
		t = new CIwuji13();
	else if(item_name == "xisuijing")
		t = new CIxisuijing();
	else if(item_name == "xuanfeng_book")
		t = new CIxuanfeng_book();
	else if(item_name == "yijing0")
		t = new CIyijing0();
	else if(item_name == "yijing1")
		t = new CIyijing1();
	else if(item_name == "yijing2")
		t = new CIyijing2();
	else if(item_name == "yijing3")
		t = new CIyijing3();
	else if(item_name == "yijinjing")
		t = new CIyijinjing();
	else if(item_name == "ylbian")
		t = new CIylbian();
	else if(item_name == "yljing")
		t = new CIyljing();
	else if(item_name == "yljian")
		t = new CIyljian();
	else if(item_name == "yljianpu")
		t = new CIyljianpu();
	else if(item_name == "yljing1")
		t = new CIyljing1();
	else if(item_name == "yljing2")
		t = new CIyljing2();
	else if(item_name == "yunv_swordb")
		t = new CIyunv_swordb();
	else if(item_name == "yunvjing1")
		t = new CIyunvjing1();
	else if(item_name == "yunvjing2")
		t = new CIyunvjing2();
	else if(item_name == "zhangfapu")
		t = new CIzhangfapu();
	else if(item_name == "zhemei_book1")
		t = new CIzhemei_book1();
	else if(item_name == "zhemei_book2")
		t = new CIzhemei_book2();
//	else if(item_name == "zhengqi_book")
//		t = new CIzhengqi_book();
	else if(item_name == "zhifapu")
		t = new CIzhifapu();
	else if(item_name == "zixia_book")
		t = new CIzixia_book();

	else if(item_name == "guide")
		t = new CIguide();
	else if(item_name == "map")
		t = new CImap();
	else if(item_name == "kuihua")
		t = new CIkuihua();
	else if(item_name == "paper")
		t = new CIpaper();
	else if(item_name == "book14_1")
		t = new CIbook14_1();
	else if(item_name == "book14_2")
		t = new CIbook14_1();
	else if(item_name == "book14_3")
		t = new CIbook14_1();
	else if(item_name == "book14_4")
		t = new CIbook14_1();
	else if(item_name == "book14_5")
		t = new CIbook14_1();
	else if(item_name == "book14_6")
		t = new CIbook14_1();
	else if(item_name == "book14_7")
		t = new CIbook14_1();
	else if(item_name == "book14_8")
		t = new CIbook14_1();

	else if(item_name == "miaoshou")
		t = new CImiaoshou();
	else if(item_name == "hanyuepai")
		t = new CIhanyuepai();
	else if(item_name == "qiankun_fake")
		t = new CIqiankun_fake();

	if(item_name == "musicbook1")
		t = new CImusicbook1();
	else if(item_name == "musicbook2")
		t = new CImusicbook2();

	else if(item_name == "chanhe_book1")
		t = new CIchanhe_book1();
    else if(item_name == "chanhe_book2")
		t = new CIchanhe_book2();
   else if(item_name == "chanhe_book3")
		t = new CIchanhe_book3();		
	else if(item_name == "chanhe_book4")
		t = new CIchanhe_book4();
   else if(item_name == "jixiao_book1")
		t = new CIjixiao_book1();
   else if(item_name == "jixiao_book2")
		t = new CIjixiao_book2();
	else if(item_name == "jixiao_book3")
		t = new CIjixiao_book3();
   else if(item_name == "jixiao_book4")
		t = new CIjixiao_book4();
   else if(item_name == "hejianjing")
		t = new CIhejianjing();	
   else if(item_name == "tangshoumichuan")
		t = new CItangshoumichuan();	
	else if(item_name == "club_book")
		t = new CIclub_book();		
	else if(item_name == "hammer_book")
		t = new CIhammer_book();	
	else if(item_name == "wumu_book1")
		t = new CIwumu_book1();	
	else if(item_name == "kao_book")
		t = new CIkao_book();	
   else if(item_name == "kill_hammer_book")
		t = new CIkill_hammer_book();	
    else if(item_name =="xiangsijianpu")
		t = new CIxiangsijianpu();	
	else if(item_name =="yicai_book1")
		t = new CIyicai_book1();
	else if(item_name =="yicai_book2")
		t = new CIyicai_book2();
	else if(item_name =="jh_zhinan1")
		t = new CIjh_zhinan1();
	else if(item_name =="kuihua_pro")
		t = new CIkuihua_pro();
	
	return t;
}



