// heimuya_laozhe ����
//code by sound
//2001-07-10

NPC_BEGIN(CNheimuya_laozhe);

virtual void create()
{
	set_name("����", "lao zhe");
	set("gender", "����" );
	set("age", 70);
	set("long","�����ͷ���麵�̳�������,�������ܺ������ϻ���?");
	set("combat_exp", 1000);
	set("attitude", "friendly");
 	set("icon",old_man1);
//	set("rank_info/respect", "�ϴ�ү");

	set("chat_chance", 5);
	
	set_inquiry("��ľ��","��ľ������һ����Ů�����ѵĳ��˶�ħ�����ǧ����ȥ��");
	set_inquiry("����","������,�ѵ��������Т��,������������Ϻõ��̲�,�Ҿ͸���һ��������");
	set_inquiry("����","����˵�Ķ��������Ϻ�ľ�µ�������,��ȥ���Ϻ��̲�,�ҵȲ�����...");
	
//	carry_object(__DIR__"obj/card4");
}

virtual char * chat_msg()		//NPC�Զ�����
{
	switch(random(2))
	{
	case 0:
//		return 	"���˼�ͷҲ����˵������λ" + RANK_D->query_respect(ob)+ "����Ҫ����,С��Ұ�ޡ�";
		return 	"���˼�ͷҲ����˵��������Ҫ����,С��Ұ�ޡ���";
	case 1:
		return 	"���˼Ҷ���˵��:��Ҳһ��������,�ͺ���һ��,������кðɡ�";
	}

	return 0;
}
/* 
void init()
{
	object ob,me,what;
 
	::init();
	ob = this_player();
	me = this_object();
//	what=new(__DIR__"obj/yancao");
//	sprintf("%s aaa\n",what);
//	command("give yancao to",me);  
	if( interactive(ob) && !is_fighting() ) {
		remove_call_out("greeting");
	call_out("greeting", 1, ob);
	}
}
 
int accept_object(object who, object ob)
{ 
	if (ob->query("money_id") && ob->value() >= 5000)
	{
	tell_object(who, "��ͷ����˵:�ã��ã����Ǹ��ú��ӡ�\n");
	
	who->set_temp("rent_paid",1);
   
	treturn 1;
	}
 
	return 0;
}
*/
NPC_END;