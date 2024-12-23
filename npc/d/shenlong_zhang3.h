// shenlong_zhang3.c

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;
//inherit F_MASTER;

NPC_BEGIN(CNshenlong_zhang3);

virtual void create()
{
	set_name("������",  "zhang laosan");
	set("title", "������СͷĿ");
	set("gender", "����");
	set("age", 44);
	set("str", 25);
	set("dex", 20);
	set("long", "����һ��������ͷ,һ˫С�۾��������⡣ ");
	set("combat_exp", 25000);
	set("score", 2000);
	set("shen_type", -1);
	set("attitude", "peaceful");
 	set("icon",old_man1);
	
	set_skill("force", 50);
	set_skill("unarmed", 70);
	set_skill("dodge", 70);
	set_skill("parry", 70);
	set_skill("yixingbu", 40);
	set_skill("shenlong_bashi", 50);
	map_skill("parry", "shenlong_bashi");
	map_skill("dodge", "yixingbu");
	
	set_temp("apply/attack", 15);
	set_temp("apply/defense", 15);
	set_temp("apply/armor", 10);
	set_temp("apply/damage", 10);
	set("mp", 500); 
	set("max_mp", 500);
	set("mp_factor", 10);
	
	set_inquiry("���"," һ�������벻���������̵�. ");
	set_inquiry("�����"," ����Ƣ������,Ҫ�������Ĳźá� ");
	set_inquiry("�ں�"," ���겻��!�����ɸ�!��������!������ʥ! ");
	
	carry_object("cloth")->wear();
}
	
virtual char * chat_msg()
{
	switch (random(5))
	{
	case 0:
		return "������ѵ,ʱ������,�����˵�,���²���! ";
	case 1:
		return "��־���Ŀɳɳ�,���������ޱ���! ";
	case 2:
		return "��������������,���������ǰ˷�! ";
	case 3:
		return "�˷����˳�Ӣ��,������ͬ���¹�! ";
	case 4:
		return "���������ɸ�,��������! ";
	}
	return "";
}
/*
virtual void init(CChar *me)
{
	add_action("do_join","join");
}
*/
virtual int recognize_apprentice(CChar * ob)
{
	if (DIFFERSTR(ob->querystr("party/party_name"), "������") )
		return 0;
	
	return 1;	
}

NPC_END;