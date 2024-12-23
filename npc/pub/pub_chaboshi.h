// pub_chaboshi.c
//code by Fisho
//date : 2000-12-13

//inherit F_DEALER;

VENDOR_BEGIN(CNpub_chaboshi);

virtual void create()
{
	set_name("�販ʿ","cha boshi");

	set("icon", pub_boss);
	set("title", "����ϰ�");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "����");
	set("age", 35);
	set("long","����販ʿ���Ǻ���������Ϣ��ͨ��ʿ��ÿ��ӭ�����������ԶԳ����һ��һ��������ָ�ơ�");
	set("combat_exp", 500);
	set("attitude", "friendly");
	
	carry_good("peanut",10);
	carry_good("tofu",10);

	carry_object("cloth")->wear();
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch(random(2)) 
	{
	case 0 :
		return snprintf(msg,255,"��λ%s������ҿ�������ȱ��Ȳ衣",query_respect(ob));
	case 1 :
		return snprintf(msg,255,"����ң���λ%s�������С�����費���ƣ�����ң�",query_respect(ob));
	}
	return "";
}
VENDOR_END;