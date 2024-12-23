//zhuwanli.h
//Lanwood 2000-01-05

NPC_BEGIN(CNdali_zhuwanli);

virtual void create()
{
	set_name("��ǧ��", "zhu qianli");
	set("title", "�Ĵ�����֮һ");
	set("age", 34);
	set("gender", "����");
	set("long", "������һ���ɫ�ٷ�����ٴ�硣���ﻹ����һ����ͣ�����ͦϲ�������");
	set("icon", young_man2);

	set("attitude", "friendly");
	set("str", 30);
	set("dex", 20);
	set("int", 20);
	set("max_force", 600);
	set("force", 600);
	set("force_factor", 20);
	set("combat_exp", 400000);
	set("repute", 100);
	set_skill("unarmed", 260);
	set_skill("dodge", 170);
	set_skill("parry", 180);
	set_skill("sword",133);
	set_skill("finger", 149);
	set_skill("literate", 110);
	set_skill("sun_finger",145);
	set_skill("force", 170);
	set_skill("whip", 260);
	set_skill("tianlong_shengong", 170);
	set_skill("qingdie_shenfa", 170);
	map_skill("dodge", "qingdie_shenfa");
	map_skill("finger","sun_finger");
	map_skill("force", "tianlong_shengong");
	create_family("����μ�", 6, "����");
	
	carry_object("junfu")->wear();
	carry_object("tiebian")->wield();
	add_money(3000);
};

virtual void attempt_apprentice(CChar * me)
{
//	int phlye = me->query("phlye");
	char msg[255];

/*	if(phlye != 5)
	{
		say(snprintf(msg, 255, "%s�ĸ��ǵ��ǲ���Ӵ����Ҳ������Ϊͽ������...", query_respect(me)), me);
		say("Ŀǰ�������ֻ���书�������ˣ��㻹�ǵ��±��Ӱɣ�", me);
		SendMenu(me);
		return;
	}
*/
	if ( me->query("betrayer") > 1 && DIFFERSTR(me->querystr("family/family_name"), "����μ�"))
	{ 
		say("����������������������£��ҽ������ɱ������ʾ���ˣ�");
		kill_ob(me);
		return ;  
	}

	if( me->query("family/generation") >= query("family/generation")
		&& EQUALSTR(me->querystr("family/family_name"), "����μ�"))
	{
		say("��ı��ֲ����ҵ��ˣ�����ô������Ϊͽ�أ�", me);
		SendMenu(me);
		return;
	}

	if (me->query("repute") < 0) 
	{
		say("�Ҵ���������������������ɣ��Ե���Ҫ���ϡ�", me);
		say(snprintf(msg, 255, "�ڵ��з��棬%s�Ƿ����ò�����", query_respect(me)), me);
		SendMenu(me);
		return;
	}

	say("�ðɣ��Ҿ��������ˡ�");
	command(snprintf(msg, 255, "recruit %ld", me->object_id()));
}


NPC_END;
