// laocai.h ���ϲ�
//zhangdongni  2001-07-18


NPC_BEGIN(CNbiatuo_laocai);

virtual void create()
{
	set_name("�ϲ�", "lao cai" );
	set("gender", "����" );
	set("nickname","�ϲ�");
	set("age", 40);
	set("long", "һ�����������Ĺ����������տ����Ų�Ҳ�ܷ����Ƶġ�\n");
	set("shen_type",-1);
	set("combat_exp", 10000);
	set("str", 30);
	set("dex", 28);
	set("con", 22);
	set("int", 24);
	set("attitude", "friendly");
	set("icon", young_man1);
	set_inquiry("��", "�����ϴ���һ��,����Ҫ��");
	
//	     carry_object("cloth")->wear();

/*
}

string inquiry_dao()
{
 object me=this_player();
 object ob;

 if (present("chai dao",me))
  return "�ϲĵ�����˵�������ϴ���һ�ѣ�����Ҫ��\n";
 else
 {
 ob=new("/d/baituo/obj/chaidao");
 ob->move(me);
  return "�ϲĵݸ���һ�Ѳ񵶣�������˵��С�ı��ܣ�\n";
 }
}
*/

}

NPC_END;