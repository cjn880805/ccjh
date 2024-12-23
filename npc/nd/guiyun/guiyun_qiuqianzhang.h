// qiuqianzhang.h 裘千丈
//code by sound
//date : 2001-07-18

NPC_BEGIN(CNguiyun_qiuqianzhang);

virtual void create()
{
	set_name("裘千尺", "qiu qianzhang");
	set("nickname", "肉掌水底钻");
	set("gender", "男性");
	set("age", 65);
	set("long", 
		"他有个弟弟叫裘千仞，他还有个妹妹叫裘千尺。他自己，虽然比弟弟\n"
		"多了三千尺，比妹妹更是多了九千尺，手上的功夫呢却比他们稀松至\n"
		"少九万尺。\n"); 
	set("per",14);
	set("icon", old_man2);
	set("combat_exp", 50000);
	set_skill("dodge", 50);
	set_skill("lingxu_bu", 50);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("changquan", 50);
	map_skill("dodge", "lingxu_bu");
	map_skill("parry", "changquan");
	map_skill("unarmed", "changquan");
	set("shen_type", -1);

//	add_money("silver",3);
	carry_object("cloth")->wear();
}

NPC_END;