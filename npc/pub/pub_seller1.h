//seller1.h
//code by zwb
//12-15

VENDOR_BEGIN(CNPub_seller1);

virtual void create()
{
	set_name("С����","seller");

	set("icon", waiter);
	set("gender", "����" );
	set("age", 32);
	set("long",	"���Ǹ�С����������������ʵʵ��ȴר��ƭ��");
	set("combat_exp", 300);
    set("str", 17);
    set("dex", 20);
    set("con", 17);
    set("int", 22);
	set("attitude", "friendly");
	set_inquiry("������" , "����Ҳ�����˾��ӣ���ô�������");

	carry_good("bottle",20);
	carry_good("egg",20);

    carry_object("cloth")->wear();
	add_money(100);

};

virtual void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && !is_fighting())
	{
		if(DIFFERSTR(me->querystr("gender"), "Ů��"))
			message_vision("$Nߺ�ȵ��������裬�����裬һҹ��˯�ٹ��", this);
	}	
}

VENDOR_END;
