//yufu.h
//code by zwb
//12-15

NPC_BEGIN(CNPub_yufu);

virtual void create()
{
	set_name("���","yu fu");
	
	set("icon", young_man4);
	set("gender", "����" );
	set("age", 22);
	create_family("���͵�", 2, "����");
};
/*
virtual int accept_object(CChar * me ,CContainer * obj)
{
	CContainer * tongpai;

	if(EQUALSTR(obj->querystr("base_name"), "coin") && obj->query("value")>=1000)
	{
		tongpai = load_item("tongpai");
		tongpai->set_temp("own", me->name(1));
		tongpai->move(me);
		message_vision("����$Nһ��ͭ�����ơ�", me);

		add_money(obj->query("value"));
	}

	return 1;
}
*/
NPC_END;
