// liwenxiu.c ������
//sound 2001-07-11

NPC_BEGIN(CNgaochang_liwenxiu);

virtual void create()
{
	set_name("������", "liwenxiu");
	set("gender", "Ů��");
	set("age", 18);
	set("long", "�������崿���㣬��ȻһЦ������������Ȼ�Ķ���");
	
	set("combat_exp", 30000);
	set("shen_type", 1);
	
	set("max_mp", 500);
	set("mp", 500);
	set("mp_factor", 10);
	set("per", 18);
	set("icon",young_woman2);			//������������
	
	set_skill("force", 40);
	set_skill("sword", 100);
	set_skill("unarmed", 50);
	set_skill("dodge", 100);
	set_skill("parry", 100);
/*	
	set("inquiry", ([
		"����" : (: ask_supu :),
		"��ĸ" : (: ask_parent :),
		"�߲��Թ�" : (: ask_gaochang:),
        ]) );
*/
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
	
	carry_object("changjian")->wield();
//	carry_object("map");
}
/*
int ask_supu()
{
	say("��������Ȼ��˵�������Ҷ�ʱ�Ļ�飬�����ںͰ�����һ���ˣ�\n");
	this_player()->set_temp("marks/��1", 1);
	return 1;
}

int ask_parent()
{
	if ((int)this_player()->query_temp("marks/��1")) {
		say("���������ʵ�˵�����ҵĸ�ĸ�Ǳ����˺����ģ������������Ǽҵĸ߲���ͼ.\n"
			"��һ��Ҫ���г��ˣ�Ϊ�Ҹ�ĸ����\n");
		this_player()->set_temp("marks/��2", 1);
		return 1;
	}
	else {
		say("������˵������ĸ֮�𣬲������졣\n");
		return 1;
	}
}

int ask_gaochang()
{
	object me;
	object map;
	me=this_player()
		if ( me->query_temp("marks/��2")) {
			say("������һ����˵��������ô֪���ģ��ޣ��Ҹղ�˵¶���ˡ�\n"
				"���ҾͰѵ�ͼ�͸���ɡ��㿴���߲��Թ�������ʲô��\n");
			map=new("/d/gaochang/obj/map");
			map->move(me);
		}
		
		else {
			message("vision",
				HIY "�����㲪Ȼ��ŭ���ȵ�����Ҳ�����Ҹ�ĸ�ĸ߲���ͼ�����Ҹ���ƴ�ˣ�\n"
				NOR, environment(), this_object() );
			kill_ob(this_player());
		}
		this_player()->delete_temp("marks/��1");
		this_player()->delete_temp("marks/��2");
		return 1;
}
*/
NPC_END;