//yinwulu.h
//Lanwood
//2001-01-09

NPC_BEGIN(CNmingjiao_yinwulu);

virtual void create()
{
	set_name("����»", "yin youlu");
	set("long","����һλ���ߣ���һ���ײ����ۡ����ǰ�üӥ��������ʹӡ�һ˫����Ŀ�������㣡");
	
	set("title",  "��������������");
	set("gender", "����");
	set("attitude", "friendly");
	set("class", "fighter");
	set("icon",old_man2);
	
	set("age", 56);
	set("shen_type", 1);
	set("str", 25);
	set("int", 25);
	set("con", 25);
	set("dex", 25);
	set("max_hp", 3000);
	set("hp", 1000);
	set("mp", 1000);
	set("max_mp", 1000);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 5000);
	
	set_skill("force", 85);
	set_skill("hunyuan_yiqi", 85);
	set_skill("dodge", 85);
	set_skill("shaolin_shenfa", 85);
	set_skill("cuff", 95);
	set_skill("jingang_quan", 95);
	set_skill("parry", 85);
	set_skill("buddhism", 85);
	set_skill("literate", 85);
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("cuff", "jingang_quan");
	map_skill("parry", "jingang_quan");
	
	prepare_skill("cuff", "jingang_quan");
	create_family("����", 4, "����������");

	set_inquiry("����",ask_for_gongzi);

	carry_object("baipao")->wear();
}

static char * ask_for_gongzi(CNpc *who,CChar *me)
{
	int paytimes;

	if (EQUALSTR(me->querystr("party/party_name"), "����"))  
	{
		if(me->query("party/level") <= 3)
			return "����»�����۸����Ϻ�Ϳ��������������ʹ�������������칤�ʣ�";
		paytimes =  me->query("mud_age") / 7200;
		if (me->query("dlpaytimes") < paytimes)
		{
			CMoney::Pay_Player(me,2000);
			me->add("dlpaytimes", 1);
			return "�����㱾�µķݶ�պðɡ�";
		}
		else 
			return "����»�����۸����Ϻ�Ϳ���㱾�¹����Ѿ���ȡ���ˣ�";
	}
	
	return "����»�����㲻�����������ˣ����������޹ء�";
}

NPC_END;