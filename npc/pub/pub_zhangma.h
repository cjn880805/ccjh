// pub_zhangma.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_zhangma);

virtual void create()
{
	set_name("����", "zhang ma" );

	set("icon", old_woman);
	set("gender", "Ů��" );
	set("age", 50);
	set("long", "һ��������ɣ�������š�");
	set("shen_type", 1);
	set("combat_exp", 500);
	set("str", 16);
	set("dex", 17);
	set("con", 17);
	set("int", 18);
	set("attitude", "friendly");
	set("chat_chance",10);
	set_inquiry("��" , inquiry_hua );
	set_temp("shoe",1);
	carry_object("cloth")->wear();
}

virtual char *chat_msg()
{
	switch (random(3))
	{
	case 0:
		return  "������߶�ţ��ҿ����ġ��𻨡�Ӵ��������������Ӵ��";
	case 1:
		return  "���谵��Ĩ�˰����ᡣ";
	case 2:
		return  "�������˵�����ҵġ��𻨡�ѽ��������Ʋ�����Ը������ˣ�";
	}
	return "";
}

static char * inquiry_hua(CNpc *ob,CChar *me)
{
	CContainer *obn;
	char msg[255];
	
	ob->say(snprintf(msg,255,"��λ%s�����𻨡����ҵ��׹�Ů�������Т˳�ˣ���ϧȥ����ɽ��ݾ�һȥ���ᣬҲ��֪�����ǻ����",query_respect(me) ), me );
	
	if(ob->query_temp("shoe")==0)
	{  
		ob->say(snprintf(msg,255,"��λ%s�����Ѿ�����ȥѰ���ˣ�Ҳ��֪����ô���ˡ�",query_respect(me) ),me);
		ob->SendMenu(me);
		return "";
	}

	ob->say(snprintf(msg,255,"��λ%s���������������ڲݴ����һֻ���廨Ь������Ҫ���ҵ����𻨡����Ͱ�Ь���������������׵ġ���Ů�����𻨡������ˣ����и����ˡ�" ,query_respect(me) ), me);
	obn=load_item("shoe");//�廨Ь
	obn->move(me);
	ob->set_temp("shoe", 0l);
	ob->SendMenu(me);
	return "";
}
NPC_END;