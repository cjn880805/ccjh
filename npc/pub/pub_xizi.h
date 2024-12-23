// pub_xizi.c
//code by Fisho
//date : 2000-12-14

NPC_BEGIN(CNpub_xizi);

virtual void create()
{
	set_name("Ϸ��", "xi zi"  );

	set("icon", young_man4);
	set("gender", "����" );
	set("age", 10+random(40));
	set("int", 28);
	set("long","���Ǹ���Ӣ�������ӡ�");
	set("attitude", "peaceful");
	set_skill("literate", 100);
	set("combat_exp",random(10000));
	set("chat_chance", 3);
	set("per", 40);

	set_inquiry("����", ask_meili );
	set_inquiry("����", "��������ʵ��̫�����ˣ�");
	
	carry_object("zichoushan")->wear();
	carry_object("gao3")->wear();
}

virtual char * chat_msg()
{
	switch (random(3))
	{
	case 0:
		return 	"Ϸ��ͻȻ˵��: ��������Ҫ�����������˶�ϲ����";
	case 1:
		return  "Ϸ�ӵ����˵: �ҵ�����ֵ��100��";
	case 2:
		return 	"Ϸ��ͻȻ˵��: �����£�Ҫ����MM�����װ�������ֵ̫�Ϳɲ��С�";
	}
	return "";
}

static char * ask_meili(CNpc * me, CChar * who)
{
	char msg[255];

	if(who->query("age") < 16)
	{
		if(! CMoney::Player_Pay(who, 1000000))
			me->say("��֪����������Ƕ���,�ȸ�100����˵��.", who);
	}
	else
		me->say(snprintf(msg, 255, "�����ڵ�����ֵ��%d��", who->query("per")), who);

	me->say("���������ֵ�ܸߣ���Ȼ�ͻ�ܶ�MM��ϲ��������", who);
	me->say("������Щʦ�����㳤�ò�Ư�����᲻���㹦��", who);
	me->say("������Щʦ���̵Ķ���һ�����MM�������á�", who);
	
	me->SendMenu(who);
	return 0;
}

NPC_END;