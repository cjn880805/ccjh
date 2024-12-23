//xy_limuou.h	“玉关八友”李木偶
//秦波 2002、12、2

NPC_BEGIN(CNxy_limuou);

void create()
{
	set_name("李木偶","li muou");
	set("gender", "男性");
	set("age", 27);
	set("long","这人脸上用油彩绘了脸谱，看上去青面獠牙，红发绿须，形状可怕之极，直是个妖怪，身上还穿了一件亮光闪闪的锦袍。");

	set("attitude", "peaceful");
	set("icon",young_man2);

	set("shen_type", 1);
	set("str", 38);
	set("int", 28);
	set("con", 30);
	set("dex", 28);
	set("per", 40);
	
	set("max_hp", 1800);
	set("mp", 600);
	set("max_mp", 600);
	set("mp_factor", 30);
	set("combat_exp", 100000);
	set("score", 20000);

	set("no_kill",1);
	
	set_skill("force", 50);
	set_skill("dodge", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("hand", 50);
	set_skill("lingboweibu", 50);
	set_skill("beiming_shengong",50);
	set_skill("liuyang_zhang", 50);
	set_skill("zhemei_shou", 50);
	
	map_skill("unarmed", "liuyang_zhang");
	map_skill("dodge", "lingboweibu");
	map_skill("force", "beiming_shengong");
	map_skill("hand", "zhemei_shou");
	map_skill("parry", "liuyang_zhang");

	prepare_skill("hand","zhemei_shou");
	prepare_skill("unarmed","liuyang_zhang");
	
	create_family("逍遥派", 3, "弟子");
	set("title","逍遥派“函谷八友”");
	set("nickname","戏痴");
	set("no_talk",1);
	set("no_huan",1);

};

virtual void init(CChar *me)
{
	CNpc::init(me);
	if(is_fighting()) return;

	if( userp(me) && !is_fighting()) 
		tell_object(me,"\n李木偶疯疯癫癫的说道：“我天赋异禀，是天生的偶像，北京的戏子凭什么就比我红呢？”\n");
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "翠羽") && EQUALSTR(ob->querystr("id"), "cuiyu")
		&& who->query_temp("xy/renwu1_61") && !who->query_temp("xy/renwu1_65") && !who->query_temp("xy/renwu1_650")  )
	{
		destruct(ob);
		tell_object(who,"\n李木偶轻轻地插上一根翠羽。");
		tell_object(who,"李木偶横卧地下，叫道：“孤王乃李存勖是也，不爱江山爱做戏，嗳，好耍啊好耍！”");
		tell_object(who,"李木偶虚着双眼，拿手指尖指着你，拖长了声音道：“爱卿~~~~可要何~~~~~赏赐！”\n");
		who->set_temp("xy/renwu1_650",1);//给李木偶翠羽
		return 1;
	}
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(! strlen(ask))
	{
		if(me->query_temp("xy/renwu1_61") && me->query_temp("xy/renwu1_650") && !me->query_temp("xy/renwu1_65"))
		{
			AddMenuItem("转告李木偶关于七夕相聚之事","qixi",me);
		}
		SendMenu(me);
		return 1;
	}
	else if(!strcmp(ask, "qixi") )
	{
		if (me->query_temp("xy/renwu1_61")&& me->query_temp("xy/renwu1_650") )
		{
			if(!me->query_temp("xy/renwu1_65") )
				me->set_temp("xy/renwu1_65",1);//通知李木偶参加七夕相聚
			say("李木偶一跃而起：“末将~~得令~！七夕之期，会~师~逍~~遥~林！呛~~呛~~呛......”",me);
		}
		else
			say("李木偶疯疯癫癫的说道：“我天赋异禀，是天生的偶像，北京的戏子凭什么就比我红呢？”",me);
		SendMenu(me);
		return 1;
	}
	else
	{
		say("李木偶疯疯癫癫的说道：“我天赋异禀，是天生的偶像，北京的戏子凭什么就比我红呢？”",me);
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

NPC_END;




