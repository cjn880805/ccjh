// pub_aqingsao.c ����ɩ
//code by Fisho
//date : 2000-12-13

//inherit F_DEALER;

VENDOR_BEGIN(CNpub_aqingsao);

virtual void create()
{
	set_name("����ɩ","qing sao");

	set("icon", young_woman9);
	set("title", "����ϰ���");
	set("nickname", "����һ֧��");
	set("shen_type", 1);

	set("str", 30);
	set("gender", "Ů��");
	set("age", 25);
	set("long","����ɩ�����ݳ��������Ĵ����ˣ���Ϊү������ϲ����������䣬�������Գ����һ��һ��������ָ�ơ�");
	set("combat_exp", 500);
	set("attitude", "friendly");

	carry_good("peanut",500);
	carry_good("tofu",500);

	carry_object("cloth")->wear();

	set_inquiry("����" , "���ǼҰ���ȥ����������ȥ��Ү��");
	set_inquiry("����" , "���ô������");
}

virtual char * greeting(CChar * ob)
{
	static char msg[255];
	switch(random(2))
	{
	case 0 :
		return snprintf(msg,255,"��λ%s����������ȱ��Ȳ衣",query_respect(ob));

	case 1 :
		return snprintf(msg,255,"Ӵ����λ%s�����˰��������и�ը�õ����㻨�����ۡ�",query_respect(ob));
		
	}

	return "";
}

VENDOR_END;