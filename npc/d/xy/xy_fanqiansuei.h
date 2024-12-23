//xy_fanqiansuei.h	“玉关八友”范千岁
//秦波 2002、12、2

NPC_BEGIN(CNxy_fanqiansuei);

void create()
{
	set_name("范千岁","fan qiansuei");
	set("gender", "男性");
	set("age", 27);
	set("long","一个相貌堂堂的黑须老者，手上还拿着方方的一块木板，那板上纵一道、横一道的画着许多直线，显然便是一块下围棋用的棋盘。");

	set("attitude", "peaceful");
	set("icon",young_man2);

	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("per", 22+random(4));
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);
	
	set_skill("force", 100);
	set_skill("dodge", 100);
	set_skill("unarmed", 100);
	set_skill("parry", 100);
	set_skill("hand", 100);
	set_skill("lingboweibu", 100);
	set_skill("beiming_shengong",100);
	set_skill("liuyang_zhang", 100);
	set_skill("zhemei_shou", 100);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");
	
	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","棋迷");
	set("no_huan",1);

};

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && me->query_temp("xy/renwu1_61") 
		&& me->query_temp("xy/renwu1_660") && !me->query_temp("xy/renwu1_661")) 
	{
		tell_object(me,"$HIC\n范千岁看了看血棋衣，摇头道：“现在看这个也没什么用了，$HIC弈棋之道在于布阵与应变，犹如行军打仗，水无常势，兵无常法$COM。看来我最终还是不能参透其最高境界呀！”\n");
		me->set_temp("xy/renwu1_661",1);//范千岁无法揭开血棋衣的秘密
	}
	else if( userp(me) && !is_fighting()&& me->query_temp("xy/renwu1_61") && !me->query_temp("xy/renwu1_660"))
	{
		kill_ob(me);
	}
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "血棋衣") && EQUALSTR(ob->querystr("id"), "zhanyi")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_66") && !who->query_temp("xy/renwu1_660") 
		&& is_fighting() )
	{
		destruct(ob);
		who->set_temp("xy/renwu1_660",1);//给范千岁血棋衣
		tell_object(who,"$HIC\n你说道：“范千岁，你不是一直想借血棋衣一看吗？我千辛万苦拿来给你，你怎还如此疯癫待我？”\n");
		return 1;
	}
	if(EQUALSTR(ob->querystr("name"), "群星璀璨图") && EQUALSTR(ob->querystr("id"), "qunxing_tu")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_66") 
		&& who->query_temp("xy/renwu1_660") && who->query_temp("xy/renwu1_661") )
	{
		destruct(ob);
		tell_object(who,"$HIC\n你说道：“这是一本通过天上群星运动而对应阵法应变道理的书，或者对你会有些用处！”");
		tell_object(who,"$HIC范千岁接过之后欣喜万分，再三言谢，你推却之下道明来意，范千岁欣然而应。");
		tell_object(who,"$HIC范千岁说道：“请转告大师兄，届时我必定准时赴约。\n");
		who->set_temp("xy/renwu1_66",1);//通知范千岁参加七夕相聚
		return 1;
	}
	return 0;
}

NPC_END;




