//liqingzhao.h
//code by zwb
//12-23
//inherit F_MASTER;

NPC_BEGIN(CNGuMu_liqingzhao);

virtual void create()
{
	set_name("李清照","li qing zhao");
	
	set("long", "她生得极为美貌，又做得一手好诗，但冰冷的目光让人不寒而栗。");
	set("nickname", "赤练仙子");
	set("gender", "女性");
	set("rank_info/respect", "道姑");
	set("age", 27);
	set("attitude","heroism");
	set("str", 30);
set("foolid",58);
set("dex", 35);
	set("con", 17);
	set("int", 25);
	set("shen_type", -1);
	set("icon",taoistess);
	
	set("hp", 7500);
	set("max_hp", 10500);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 80);
	
	set("combat_exp", 1200000);
	
	
	set_skill("force", 200);
	set_skill("yunv_xinfa", 200);    //玉女心法
	set_skill("sword", 180);
	set_skill("yunv_jian", 180);     //玉女剑
	set_skill("dodge", 220);
	set_skill("yunv_shenfa", 220);   //玉女身法
	set_skill("parry", 200);
	set_skill("unarmed",200);
	set_skill("wudu_shenzhang", 220);    //五毒神掌
	set_skill("wudu_xinfa", 220);
	set_skill("whip", 250);
	set_skill("swsb_whip", 250);//三无三不手
	set_skill("literate", 180);
	set_skill("tianluo_diwang", 220);
	
	map_skill("force", "yunv_xinfa");
	map_skill("sword", "yunv_jian");
	map_skill("dodge", "yunv_shenfa");
	map_skill("parry", "wudu_shenzhang");
	map_skill("unarmed", "wudu_shenzhang");
	
	set_inquiry("姓名","站远点！");
	set_inquiry("地名","我不是本地人，不知道。");
	set_inquiry("情","你如何能理解其中相思之苦、惆怅之意？");
	set_inquiry("陆郎","你问那个薄情的人做什么？");
	set_inquiry("雪","雪是一把无敌天下的刀。");
	set_inquiry("陆夫人",ask_me );
	set_inquiry("龙儿","那是我的师妹。你问她想干什么？");
	set_inquiry("林照茵","那是我的师祖，不该你问的你别问，小心我宰了你。");
	set_inquiry("冰魄银针",ask_zhen );
	set_inquiry("静心口服液","那是我冰魄银针的独门解药，平时我用来养颜的。" );
	
	create_family("古墓派", 3, "弟子");
	set("chat_chance", 10);
	set_temp("have_zhen", 5);
	
	carry_object("greenrobe")->wear();
	carry_object("jingxin_san", 3);
	set("no_huan",1);
}

virtual char * chat_msg(CChar * player)
{
	switch(random(8))
	{
	case 0:
		return "李清照纵声而歌，音调凄婉，歌道：「问世间，情是何物，直教生死相许？」";
	case 1:
		return "「天南地北双飞客，老翅几回寒暑？」";
	case 2:
		return "「欢乐趣，离别苦，就中更有痴儿女。」";
	case 3:
		return "「君应有语，渺万里层云，千山暮雪，只影向谁去？」";
	case 4:
		return "李清照词意悲切，声调更是哀怨，唱道：「横汾路，寂寞当年箫鼓。荒烟依旧平楚。」";
	case 5:
		return "「招魂些何嗟及，山鬼自啼风雨。」";
	case 6:
		return "「天也妒，未信兴，莺儿燕子俱黄土。」";
	case 7:
		return "「千秋万古，为留待骚人，狂歌痛饮，来访雁丘处。」";
	}
	return "";
}

static char * ask_me(CNpc * npc , CChar * player)
{
	char msg[255];

	message_vision("李清照冷笑一声：『我这就送你去见她』", player);
	message_vision(snprintf(msg,255,"李清照决心杀死%s",player->name()),player);
    npc->kill_ob(player);
	return "";
}

static char * ask_zhen(CNpc * npc , CChar * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "古墓派") && DIFFERSTR(player->querystr("class"), "taoist"))
		return "你不是我门下传人，不给不给。";
	if(player->query_temp("mark/get_bt_zhen"))
		return "你不是刚拿过吗？不要那么贪心好不好？";
	if(npc->query("have_zhen") < 0)
		return "你来迟了，银针已给了你其他同门了。";

	load_item("bt_zhen")->move(player);

	player->set_temp("mark/get_bt_zhen",1);
	npc->add_temp("have_zhen", -1);

	message_vision("李清照给了$N一把冰魄银针。", player);
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if ( DIFFERSTR(ob->querystr("id"), "Snow blade") || DIFFERSTR(ob->querystr("name"), "清雪流光斩") )
	{	
		message_vision("$N冷冷的道：这是什么东西？", this);
		return 0;
	}

	destruct(ob);

	ob=load_item("guyuepai");

	ob->set_name( "明月牌", "mingyue pai");
	
	message_vision("$N点点头，偷偷给$n一块东西。", this, who);
	ob->move(who);

	return 1;
}

virtual void attempt_apprentice(CChar  * player)
{
	if(DIFFERSTR(player->querystr("family/family_name"), "古墓派"))
	{
		say(" 我不收别派弟子。",player);
		SendMenu(player);
		return;
	}
	if(EQUALSTR(player->querystr("class"), "taoist"))
	{
		say(" 你不去钻地道当死人来找我干什么？",player);
		SendMenu(player);
		return;
	}
	if(player->query_dex() < 25)
	{
		say(" 你的身法太差，不适合学我古墓派的武功。",player);
		SendMenu(player);
		return;
	}
	if(player->query_int() < 35)
	{
		say(" 你的悟性太差，不适合学我古墓派的武功。",player);
		SendMenu(player);
		return;
	}
	if(player->query("repute") > -50000)
	{
		say(" 我是出名的女魔头，你这点道行还想当我徒弟？",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("yunv_xinfa",1) < 90)
	{
		say(" 你的本门心法不熟，就这点道行还想当我徒弟？",player);
		SendMenu(player);
		return;
	}
	if(player->query_skill("tianluo_diwang",1) < 90)
	{
		say(" 你的天罗地网势太差，就这点道行还想当我徒弟？",player);
		SendMenu(player);
		return;
	}

	else
	{
	    say(" 好吧，我就收下你这个徒弟了。");
		recruit_apprentice(player);
	}
	return;
}

NPC_END;
