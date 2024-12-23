//qing_yuan.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_qing_yuan);

virtual void create()
{
	set_name("清缘比丘", "qingyuan biqiu");
	set("long",	"他是一位体格强健的壮年僧人，他身得虎背熊腰，全身似乎蕴含着无穷劲力。他身穿一袭白布黑边袈裟，似乎身怀武艺。");
	
	set("gender", "男性");
	set("attitude", "friendly");
	set("class", "bonze");
	set("icon",old_monk);
	set("foolid",94);
	set("age", 30);
	set("shen_type", 1);
	set("str", 21);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1050);
	
	set("mp", 350);
	set("max_mp", 350);
	set("mp_factor", 30);
	set("combat_exp", 5000);
	set("score", 100);

	set_skill("force", 30);
	set_skill("hunyuan_yiqi", 30);
	set_skill("dodge", 30);
	set_skill("shaolin_shenfa", 30);
	set_skill("strike", 30);
	set_skill("qianye_shou", 30);
	set_skill("parry", 30);
	set_skill("buddhism", 30);
	set_skill("literate", 30);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("strike", "qianye_shou");
	map_skill("parry", "qianye_shou");

	prepare_skill("strike", "qianye_shou");

	create_family("少林派", 40, "弟子");
    carry_object("xu_cloth")->wear();
};

virtual void init(CChar * me)
{	
	CNpc::init(me);

	if(userp(me) && !is_fighting() ) 
	{
		remove_call_out(do_speaking);
		call_out(do_speaking, 1);
	}
}

static void do_speaking(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	if ( random(5) < 1 ) 
	{	
		switch( random(4) ) 
		{
		case 0:
               me->say("百年前的一场大火，整个少林寺就除这监牢和北边的钟楼没遭灾。唉。。。");
		       break;
		case 1:
               me->say("这里四周全用钢汁浇缝的花岗岩给封了起来，你们就是变成苍蝇也飞不出去！");
		       break;
		case 2:
               me->say("好好呆着别动，等会儿自然会放你们出去，不过你们自己要打架我可不管！");
		       break;
		case 3:
               me->say("嘿，历年来多少巨奸大盗都在这里被关过，北边牢里的狱卒就是其中一个。");
		       break;
		}
	}
}

NPC_END;
