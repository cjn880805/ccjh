// pub_huo.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_huo);

virtual void create()
{
	set_name("������", "huo xiansheng");

	set("icon", old_man1);
	set("long","��һ�����ݣ�����ί�����������Ժ�����˯����ģ����������������ʮ�������޿����ޡ�ԭ�������Ƿ�ţ�ɵĴ�ǧ����Ϊ�ܳ�������ڴˡ�");
	
	set("gender", "����");
	set("attitude", "heroism");
	
	set("age", 51);
	
	set("str", 25);
	set("int", 20);
	set("con", 20);
	set("dex", 25);
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 100);
	set("combat_exp", 100000);
	set("score", 100);
	set("apply/attack",  30);
	set("apply/defense", 30);
	
	set_skill("force", 50);
	set_skill("unarmed", 50);
	set_skill("sword", 50);
	set_skill("dodge", 50);
	set_skill("parry", 50);
	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	add_money(5000);
	
	set_inquiry("����",ask_for_gongzi);
}

static char * ask_for_gongzi(CNpc *who,CChar *me)
{
	int paytimes;
	const char * oldtitle = me->querystr("title");

	if (strstr(oldtitle, "�������������佫"))  
	{
		paytimes =  me->query("mud_age") / 7200;
		if (me->query("dlpaytimes") < paytimes)
		{
			CMoney::Pay_Player(me,10000);
			me->add("dlpaytimes", 1);
			return "�����㱾�µķݶ�պðɡ�";
		}
		else 
			return "�����������۸����Ϻ�Ϳ���㱾�¹����Ѿ���ȡ���ˣ�";
	}
	
	return "�����������۸����Ϻ�Ϳ�������������������������佫�������칤�ʣ�";
}

NPC_END;