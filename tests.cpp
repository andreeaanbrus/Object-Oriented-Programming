//////
////// Created by Andreea on 3/22/2018.
//////
//
//
//#include <iostream>
//#include "tests.h"
//#include "dynamic_array.h"
//#include "repository.h"
//#include "controller.h"
//#include "domain.h"
//#include "dynamic_array.h"
//#include "Comparator.h"
//
//// Terminal : gcov main.gcno && lcov --capture --directory . --output-file LCOVOUTPUT.info && genhtml LCOVOUTPUT.info --output-directory CODE_COVERAGE
//
//TEST_F(Test,testDynamicArray) {
//    DynamicArray<Dog> da;
//    DynamicArray<Dog> da1;
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    da.add(d1);
//    da.add(d2);
//    da.add(d3);
//    ASSERT_EQ(da[0].getAge(), 1);
//    ASSERT_EQ(da[0].getBreed(), "breed1");
//    ASSERT_EQ(da[0].getPhoto(), "sdsdfds");
//    ASSERT_EQ(da[1].getAge(), 2);
//    ASSERT_EQ(da[2].getAge(), 3);
//    da.update(0, d3);
//    ASSERT_EQ(da[0].getAge(), 3);
//    da.remove(1);
//    ASSERT_EQ(da[1].getAge(), 3);
//    da1 = da;
//    ASSERT_EQ(da.getSize(), da1.getSize());
//}
//
//
//TEST_F(Test, testFindByNameList) {
//    AdoptionList al{};
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    al.add(d1);
//    al.add(d2);
//    al.add(d3);
//    ASSERT_EQ(al.findByName("name3"), true);
//    ASSERT_EQ(al.findByName("name1"), true);
//    ASSERT_EQ(al.findByName("name4"), false);
//}
//
//TEST_F(Test, testResize) {
//
//    Dog d1("breed1", "name1", 1, "abc");
//    DynamicArray<Dog> da;
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    da.add(d1);
//    ASSERT_EQ(da.getSize(), 11);
//}
//
//TEST_F(Test, testCopyConstructorDA) {
//    DynamicArray<Dog> da;
//    Dog d1("breed1", "name1", 1, "abc");
//    da.add(d1);
//    DynamicArray<Dog> da2(da);
//    ASSERT_EQ(da2.getSize(), 1);
//    ASSERT_EQ(da2.getAllElems()[0].getName(), "name1");
//}
//
//TEST_F(Test, testAddDog) {
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    Repository repo{};
//    repo.add(d1);
//    ASSERT_EQ(repo.getDogs()[0].getAge(), 1);
//    repo.add(d2);
//    ASSERT_EQ(repo.getLen(), 2);
//    repo.add(d3);
//    ASSERT_EQ(repo.getDogs()[2].getAge(), 3);
//}
//
////TEST_F(Test, testAddToPosition) {
////    Dog d1("breed1", "name1", 1, "sdsdfds");
////    Dog d2("breed2", "name2", 2, "sdsdfds");
////    Dog d3("breed3", "name3", 3, "sdsdfds");
////    Repository repo{};
////    repo.add(d2);
////    repo.addToPosition(1, d1);
////    ASSERT_EQ(repo.getDogs()[0].getAge(), 2);
////    ASSERT_EQ(repo.getDogs()[1].getAge(), 1);
////}
//
//TEST_F(Test, testGetList) {
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    Repository repo{};
//    repo.add(d1);
//    repo.add(d2);
//    repo.add(d3);
//    Controller c(repo);
//    ASSERT_EQ(c.getList().isEmpty(), true);
//
//}
//
//TEST_F(Test, testAddController) {
//    Repository repo{};
//    Controller controller { repo };
//    controller.add("breed1", "name1", 1, "dasa");
//    ASSERT_EQ(controller.getRepo().getLen(), 1);
//    ASSERT_EQ(controller.getRepo().getDogs()[0].getAge(), 1);
//    ASSERT_EQ(controller.getRepo().getDogs()[0].getBreed(), "breed1");
//    controller.add("breed2", "name2", 2, "dsad");
//    ASSERT_EQ(controller.getRepo().getLen(), 2);
//    ASSERT_ANY_THROW(controller.add("breed1", "name2", 3, "dsfs"));
//}
//
//TEST_F(Test, testUpdateDog) {
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    Repository repo{};
//    repo.add(d1);
//    repo.add(d2);
//    repo.update(0, d2);
//    ASSERT_EQ(repo.getDogs()[0].getAge(),  2);
//    repo.update(1, d3);
//    ASSERT_EQ(repo.getDogs()[1].getAge(), 3);
//}
//
//TEST_F(Test,testRemoveController) {
//    Repository repo{};
//    Controller controller { repo };
//    controller.add("breed1", "name1", 1, "dasa");
//    controller.remove("name1");
//    ASSERT_EQ(controller.getRepo().getLen(), 0);
//    ASSERT_ANY_THROW(controller.remove("name2"));
//}
//
//TEST_F(Test, testFindInController) {
//    Repository repo{};
//    Controller controller {repo};
//    controller.add("breed1", "name1", 1, "dasa");
//    controller.add("breed2", "name2", 2, "bsds");
//    controller.add("breed3", "name3", 3, "dssa");
//    controller.add("breed4", "name4", 4, "dssa");
//    ASSERT_EQ(controller.findInRepo("name2") , 1);
//    ASSERT_EQ(controller.findInRepo("name3") , 2);
//}
//
//TEST_F(Test, testRemoveDA) {
//    DynamicArray<Dog> da;
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    da.add(d1);
//    da.add(d2);
//    da.add(d3);
//    da = da - d1;
//    ASSERT_EQ(da.getSize(), 2);
//    ASSERT_EQ(da.getAllElems()[0].getAge(), d2.getAge());
//    da = da - d2;
//    ASSERT_EQ(da.getSize(), 1);
//    ASSERT_EQ(da.getAllElems()[0].getAge(), d3.getAge());
//}
//TEST_F(Test, testRemoveDog) {
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    Repository repo{};
//    repo.add(d1);
//    repo.add(d2);
//    repo.add(d3);
//    repo.remove(7);
//    ASSERT_EQ(repo.getLen(), 3);
//    repo.remove(0);
//    ASSERT_EQ(repo.getLen(),  2);
//    ASSERT_EQ(repo.getDogs()[0].getAge(), 2);
//    repo.remove(0);
//    ASSERT_EQ(repo.getLen(), 1);
//    ASSERT_EQ(repo.getDogs()[0].getAge(), 3);
//    repo.remove(0);
//    ASSERT_EQ(repo.getLen(), 0);
//}
//
//TEST_F(Test, testUpdateController) {
//    Repository repo{};
//    Controller controller { repo };
//    controller.add("breed1", "name1", 1, "dasa");
//    controller.add("breed2", "name2", 2, "bsds");
//    controller.update("name2", "breed3", 3, "dssa");
//    ASSERT_EQ(controller.getRepo().getDogs()[1].getBreed(), "breed3");
//    ASSERT_ANY_THROW(controller.update("name3", "breed1", 3, "ds"));
//}
//
//
//TEST_F(Test, testToString) {
//    Dog d1("breed1", "name1", 1, "abc");
//    std::string s1 = d1.toString();
//    ASSERT_EQ(s1, "Breed: breed1 | Name: name1 | Age: 1");
//}
//
//TEST_F(Test, testAdoptionList) {
//    AdoptionList ad;
//    Dog d1("breed1", "name1", 1, "https://www.youtube.com/watch?v=0Pdl0oIwCgw&list=LLYdmEo09WtfvkyMVwkkgTMA&index=2&t=0s");
//    ASSERT_EQ(ad.isEmpty(), true);
//    EXPECT_NO_THROW(ad.next());
//    ad.add(d1);
//    ASSERT_EQ(ad.getSize(),1);
//    ASSERT_EQ(ad.getCurrentDog(0).getBreed(), d1.getBreed());
//    ASSERT_EQ(ad.isEmpty(), false);
//    Dog d2("breed1", "name1", 1, "https://www.youtube.com/watch?v=0Pdl0oIwCgw&list=LLYdmEo09WtfvkyMVwkkgTMA&index=2&t=0s");
//    ad.add(d2);
//    ad.next();
//}
//
//TEST_F(Test, testFindByName) {
//    Dog d1("breed1", "name1", 1, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    Repository repo{};
//    repo.add(d1);
//    repo.add(d2);
//    repo.add(d3);
//    int x = 0;
//    ASSERT_EQ(repo.findByName("name3"), 2);
//    x = repo.findByName("name4");
//    ASSERT_EQ(x, -1);
//}
//
//TEST_F(Test, testFilterByAge) {
//    Dog d1("breed1", "name1", 2, "sdsdfds");
//    Dog d2("breed2", "name2", 2, "sdsdfds");
//    Dog d3("breed3", "name3", 3, "sdsdfds");
//    Repository repo{};
//    repo.add(d1);
//    repo.add(d2);
//    repo.add(d3);
//    Controller c(repo);
//    Repository r2{};
//    r2 = c.filterByAge(2);
//    ASSERT_EQ(r2.getLen(), 2);
//    ASSERT_EQ(r2.getDogs()[0].getName(), "name1");
//
//}
//
//
//TEST_F(Test, testSortByAge) {
//
//    Dog d1("breed1", "name1", 2, "sdsdfds");
//    Dog d2("breed2", "name2", 1, "sdsdfds");
//    Dog d3("breed4", "name4", 9, "sdsdfds");
//    Dog d4("breed3", "name3", 3, "sdsdfds");
//    DynamicArray <Dog> da {};
//    da.add(d1);
//    da.add(d2);
//    da.add(d3);
//    da.add(d4);
//    Comparator<Dog> * x = new CompareAscendingByAge{};
//    sortDogs(da, x);
//
//    for (int i = 0; i < da.getSize(); i++)
//        std::cout << da.getAllElems()[i].toString() << '\n';
//
//    ASSERT_EQ(da.getAllElems()[0].getName(), d2.getName());
//    ASSERT_EQ(da.getAllElems()[1].getName(), d1.getName());
//    ASSERT_EQ(da.getAllElems()[2].getName(), d4.getName());
//    ASSERT_EQ(da.getAllElems()[3].getName(), d3.getName());
//    delete x;
//}
//
//TEST_F(Test, testSortByName) {
//    Dog d1("breed1", "Lessie", 3, "dssad");
//    Dog d2("breed1", "Blacky", 3, "dssad");
//    Dog d3("breed1", "Missy", 3, "dssad");
//    Dog d4("breed1", "Ricky", 3, "dssad");
//    DynamicArray<Dog> da{};
//    da.add(d1);
//    da.add(d2);
//    da.add(d3);
//    da.add(d4);
//    Comparator<Dog> *x = new CompareDescendingByName{};
//    sortDogs(da, x);
//
//
//    for (int i = 0; i < da.getSize(); i++)
//        std::cout << da.getAllElems()[i].toString() << '\n';
//
//    ASSERT_EQ(da.getAllElems()[0].getName(), d4.getName());
//    ASSERT_EQ(da.getAllElems()[1].getName(), d3.getName());
//    ASSERT_EQ(da.getAllElems()[2].getName(), d1.getName());
//    ASSERT_EQ(da.getAllElems()[3].getName(), d2.getName());
//    delete x;
//}