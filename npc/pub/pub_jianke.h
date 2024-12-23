NPC_BEGIN(CNpub_jianke);

virtual void create()
{
	set_name("����","jianke");

	set("icon", taoist_with_sword);
	set("gender", "����");
	set("age", 45);
	set("long","����λ�������ˣ��米�����������Ľ������Ʈ������ƺ������ա�");
	set("combat_exp", 20000);
        set("shen_type", -1);
	set("attitude", "heroism");

	set("apply/attack",  30);
	set("apply/defense", 30);

	set_skill("sword", 60);
	set_skill("unarmed", 50);
	set_skill("parry", 50);
	set_skill("dodge", 50);


    carry_object("changjian")->wield();
    carry_object("cloth")->wear();
	add_money(20);


};

virtual void init(CChar * me)
{
	const char * mengzhu = "";
	CChar * ob;
	
	CContainer * r = load_room("̩ɽ����̨");
	
	if(( ob = (CChar *)r->PresentName("mengzhu", IS_CHAR)) )
		mengzhu = ob->querystr("winner");

	if( EQUALSTR(me->querystr("id"), mengzhu) ) 
	{
		message_vision("������$N����Ϊ��˵�������������˼Һã�", me);
	}	
}

NPC_END;
