// pub_chen.c
//code by Fisho
//date : 2000-12-13

//inherit F_DEALER;

VENDOR_BEGIN(CNpub_chen);

virtual void create()
{
	set_name("�°���", "chen apo");

	set("icon", young_woman1);
	set("title", "�ӻ����ϰ���");
	set("shen_type", 1);
	
	set("str", 20);
	set("gender", "Ů��");
	set("age", 55);
	set("long",		"�°��žþ�Ȫ�ݳǣ���˵������ʱ���м��ַ��ϣ������ھֵ�ʱ������ͷ�����ϻ�׷�������");
	set("combat_exp", 800);
	set("attitude", "friendly");
	
	carry_good("xiuhua", 10);
	carry_good("shoes", 10);
	carry_good("pink_cloth", 10);
	carry_good("goldring", 10);
	carry_good("necklace", 10);
	
	set_inquiry("������" ,"���������ǿ����ǻ���һ�����������ţ�����");
	set_inquiry("name", "�����ҷ���ճ¡����ְ�����");
	set_inquiry("here","Ȫ���Ǹ��ۿڣ����д����˺ܶࡣ");
	
}

virtual char * greeting(CChar * ob)
{
	switch(random(2))
	{
	case 0 :
		return "�˿�������";

	case 1 :
		return "����ģ���Ҫ��ʲ��";

	}
	return "";
}

VENDOR_END;