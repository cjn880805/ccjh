// zhuangyu.h
//zhangdongni 2001-07-18

NPC_BEGIN(CNcity2_zhuangyu);

virtual void create()
{
	set_name("ׯӦ��", "zhuangyingcheng");
	set("gender", "����");
	set("age", 40);
	set("icon",young_man3);
	set("ser", 15);
	set("int", 25);
	set("dex", 15);
	set("con", 20);
	set("shen_type", 1);
	set("long", "���Ǹ�����ʫ�飬ȴ���޲���֮������������༭����ʷ���ԡ�������֮�ٸ淢��ȫ�Ҵ��뾩�С�" );
	set("attitude", "peaceful");
	set_skill("literate", 100);
//	set("noget", "ׯ�ʳ�̾�����Ҳ����ˣ����߰ɡ������ҵ����Ҽ����˰���\n");
	set("chat_chance", 2);
        set_inquiry("����" , "���ݵ��鷿���б�����");
	set_inquiry("�鷿" , "�鷿���Ƿ�������ѧ��.");
}
	
virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(6))
	{
	case 0:
		return 	"ׯӦ��˵����ֻ���ҵ������ģ������м��˽�Ҷ��������";
	case 1:
	        return  "˭�������Ĺ��εļһﾹȻ��ȥ�淢���ҡ���...";
	case 2:
	        return  "ׯӦ��˵����˭Ҫ����֮��ץ��ׯ���ͺ��ˡ�";
	case 3:
	        return  "ׯӦ��ͻȻ˵��: ������������Ҫ�������ߴ��кô�����";
	case 4:
		return  "ׯӦ��̾�˿�����˵������֪�������鷿�����ܣ�ֻ��ϧ�ҳ���ȥ����";
	case 5:
		return  "ׯӦ��˵����˭Ҫ�����ң���һ������֪���Ķ���������";
	}
	return 0;
}

//{
//	set_inquiry("��" , "�ƶ��Ƿ���ʱ�����з���ġ�");
//		"����" :  "�ƶ��Ƿ���ʱ�����з���ġ�",
//		"����" :  "������һ�£�������һ�¾����ˡ�",
//		"����" :  "�ǿɲ������������������ѧ�ʵġ�",
//		"��֮��" :  "�����͵�ׯ��ȥ�кô���",
//                "����" :  (: ask_weiwang :),
//                "��������" : (: ask_weiwang :),

//}
/*
int ask_weiwang()
{
command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(this_player()->query("weiwang")));
say("\nׯ�ʳ�˵�����������ֵ�ܸߣ���Щ�˼����㲻������ɱ�㣬��������书�����㱦����\n"
+"�����㻹���Լ����ᣬ�������ȥ����Ŀ�꣬����ȥǮׯȡǮҲ������Ϣ ����������\n");
say("ׯ�ʳ���˵��ɱĳЩ���˻��ĳЩ���˿�����߽���������\n");
return 1;
}

void init()
{
	object ob; 
	int i;
	ob = this_player();
        if(!userp(ob)) return;
	if(interactive(ob) && !is_fighting() ) 
	say( "ׯ�ʳǹ���Ц�������������������ˣ�\n��λ" + RANK_D->query_respect(ob)
				+ "�������ı����ɲ��ٰ�����Ҫ��ʲô�����׵ģ��������Ұɡ�\n");
	i=(int)this_player()->query("weiwang");
        if(i<20) 
	{
	i=i+10;
        this_player()->set("weiwang",i);
	message_vision(HIC "\n$N�Ľ�����������ˣ�\n" NOR,this_player());
	}
	command("tell "+this_player()->query("id")+" �����ڵĽ��������� " +(string)(i));
}

int accept_object(object me, object ob)
{
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("name") == "��ʷ����") 
	{
	 write(HIC "\nׯ�ʳ�Ц���������н�Ҷ�ӣ��ѵ��㲻֪����\n" NOR);
	 write(HIC "ׯ�ʳ�˵�����Ұ���֮������ץ��ׯ��ȥ�ɣ��Ҳ����ˡ�\n" NOR);		
	 write("ׯ�ʳǴ��˿�������˵��ׯ���ھ��Ƕ����ߡ�\n");
	}		
        return 1;
        
        carry_object("cloth")->wear();
}

*/
NPC_END;