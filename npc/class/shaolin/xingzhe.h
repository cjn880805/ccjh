//xingzhe.h
//Lanwood 2000-01-10

NPC_BEGIN(CNshaolin_xingzhe);

virtual void create()
{
	set_name("行者", "xingzhe");
	set("title", "少林刀僧");
	set("long",	"他是一位云游四方的行者，风霜满面，行色匆匆，似乎正在办一件急事。");

	set("gender", "男性");
	set("attitude", "heroism");
	set("class", "bonze");
	set("icon",young_monk);
	set("foolid",112);
	set("chat_chance", 3);

	set("age", 35);
	set("shen_type", 1);
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 30);
	set("combat_exp", 20000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("blade", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	set_skill("shaolin_shenfa", 50);
	set_skill("cibei_dao", 50);
	set_skill("hunyuan_yiqi", 50);

	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("blade", "cibei_dao");
	map_skill("parry", "cibei_dao");

	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
	add_money(5000);
};

virtual char * chat_msg()
{
	switch(random(12))
	{
	case 0:
		return 	"行者说道：据说本寺後山山顶上有一个蕴含无上降魔大法的金刚伏魔圈，内有佛家法宝。";
	case 1:
        return  "行者说道：易筋经分为修行篇，攻防篇，身法篇与拳术篇四部，百年前便都已散失各处。";
	case 2:
		return  "行者说道：大金刚拳刚猛狠辣，最厉害的一招名称叫做如来笑，最合佛家超渡世人的本意。";
	case 3:
        return  "行者说道：本寺十八罗汉大阵威力无比，能破阵出关者可说是凤毛麟角，万里挑一的人才。";
	case 4:
        return  "行者说道：本寺弟子自上而下，依次是五圣僧，十八罗汉，九尊者，九禅师，九比丘等。";
	case 5:
        return  "行者说道：戒律院主持是玄痛大师，全寺上下众僧见了他，真是大气也不敢吭一声。";
	case 6:
        return  "行者说道：少林寺藏经楼藏经之富，天下罕有。佛法经典，武功秘籍，可以说是无所不包。";
	case 7:
        return  "行者说道：本寺弟子如要习武防身，可到後殿武器库和防具库领取器械，用後归还所司。";
	case 8:
        return  "行者说道：少林历代有许多高僧在寺内钟楼顶上勤修佛法，七层窗外平台上更是禅定妙处。";
	case 9:
        return  "行者说道：少林绝艺七十二，专精一门，固是大有好处，但如能融贯数艺，则威力更强。";
	case 10:
        return  "行者说道：本寺弟子如能较技战胜师尊辈，便可名列与彼同班，拜师学习更高深的武艺。";
	case 11:
		random_move();
		return 0;
	};
	
	return 0;
}

virtual void init(CChar * me)
{
	CNpc::init(me);

	if ( userp(me) && !is_fighting()
		&& ! environment()->query("no_fight")
		&& ( DIFFERSTR(me->querystr("family/family_name"), "少林派") && EQUALSTR(me->querystr("class"), "bonze")) )
	{
		say("你这个无耻少林叛徒，纳命来吧！！！");
		set_leader(me);
		remove_call_out(do_killing);
		call_out(do_killing, 1, me->object_id()); 
	}       
}

static void do_killing(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

	me->kill_ob(who);
}

NPC_END;
